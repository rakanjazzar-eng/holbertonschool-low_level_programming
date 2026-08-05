#!/bin/bash

set -e

if [ ! -f source.c ]; then
    echo "Error: source.c is not inside dynamic_analysis"
    exit 1
fi

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g -gdwarf-4 -O0 \
    source.c -o gdb_program

printf '123456\n' > gdb_input.txt

cat > extract_values.py <<'PYTHON'
import gdb
import re

SOURCE_FILE = "source.c"


def uint32(expression):
    value = int(gdb.parse_and_eval(expression))
    return value & 0xFFFFFFFF


def current_line():
    frame = gdb.selected_frame()
    sal = frame.find_sal()
    return sal.line if sal.symtab else -1


def function_range(lines, function_name):
    start = None

    pattern = re.compile(r"\b" + re.escape(function_name) + r"\s*\(")

    for index, line in enumerate(lines):
        if pattern.search(line):
            start = index
            break

    if start is None:
        raise RuntimeError("Could not find " + function_name)

    brace_count = 0
    started = False

    for index in range(start, len(lines)):
        for char in lines[index]:
            if char == "{":
                brace_count += 1
                started = True
            elif char == "}":
                brace_count -= 1

        if started and brace_count == 0:
            return start, index

    raise RuntimeError("Could not determine function range")


def matching_brace(lines, start_index, end_index):
    brace_count = 0
    started = False

    for index in range(start_index, end_index + 1):
        for char in lines[index]:
            if char == "{":
                brace_count += 1
                started = True
            elif char == "}":
                brace_count -= 1

        if started and brace_count == 0:
            return index

    raise RuntimeError("Could not find matching brace")


def next_code_line(lines, index, end_index):
    index += 1

    while index <= end_index:
        stripped = lines[index].strip()

        if stripped and not stripped.startswith("//"):
            return index

        index += 1

    raise RuntimeError("Could not find next code line")


with open(SOURCE_FILE, "r", encoding="utf-8") as file:
    source_lines = file.readlines()

derive_start, derive_end = function_range(source_lines, "derive_key")

loop_start = None

for index in range(derive_start, derive_end + 1):
    line = source_lines[index]

    if re.search(r"\b(for|while)\s*\(", line):
        loop_start = index
        break

if loop_start is None:
    raise RuntimeError("Could not find the loop inside derive_key")

loop_end = matching_brace(source_lines, loop_start, derive_end)
tag_line_index = next_code_line(source_lines, loop_end, derive_end)
tag_line = tag_line_index + 1

return_line = None

for index in range(derive_start, derive_end + 1):
    if re.search(r"\breturn\s+x\s*;", source_lines[index]):
        return_line = index + 1

if return_line is None:
    raise RuntimeError("Could not find return x inside derive_key")

tag_breakpoint = gdb.Breakpoint(
    SOURCE_FILE + ":" + str(tag_line),
    temporary=True
)

return_breakpoint = gdb.Breakpoint(
    SOURCE_FILE + ":" + str(return_line),
    temporary=True
)

compute_breakpoint = gdb.Breakpoint(
    "compute_target",
    temporary=True
)

gdb.execute("run < gdb_input.txt")

tag_acc = uint32("x")

gdb.execute("continue")

key = uint32("x")

gdb.execute("continue")

seen_i_zero = False
acc_after_i0 = None

for step_number in range(10000):
    try:
        before_i = int(gdb.parse_and_eval("i"))
    except gdb.error:
        before_i = None

    if before_i == 0:
        seen_i_zero = True

    try:
        gdb.execute("next", to_string=True)
    except gdb.error:
        pass

    try:
        after_i = int(gdb.parse_and_eval("i"))
    except gdb.error:
        after_i = None

    if seen_i_zero and before_i == 0 and after_i != 0:
        acc_after_i0 = uint32("acc")
        break

if acc_after_i0 is None:
    raise RuntimeError("Could not extract acc after i == 0")

with open("gdb_fundamentals.txt", "w", encoding="ascii") as output:
    output.write("0x%08X\n" % tag_acc)
    output.write("0x%08X\n" % key)
    output.write("0x%08X\n" % acc_after_i0)

print("")
print("Created gdb_fundamentals.txt:")
print("0x%08X" % tag_acc)
print("0x%08X" % key)
print("0x%08X" % acc_after_i0)

gdb.execute("quit")
PYTHON

gdb -q -batch -x extract_values.py ./gdb_program

rm -f gdb_program gdb_input.txt extract_values.py

echo
echo "Final file:"
cat gdb_fundamentals.txt
