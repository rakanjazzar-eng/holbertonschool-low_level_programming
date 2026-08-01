# 0x0E. C - Function pointers

## Description
This project covers the execution, usage, and applications of function pointers in C, including dynamic function selection, array iteration, custom search logic, and analyzing raw function opcodes in memory.

## Tasks

| Task | File | Description | Status |
| :---: | --- | --- | --- |
| **0** | `0-print_name.c` | Writes a function that prints a name using a function pointer. | <ul><li>[x] Completed</li></ul> |
| **1** | `1-array_iterator.c` | Executes a function given as a parameter on each element of an array. | <ul><li>[x] Completed</li></ul> |
| **2** | `2-int_index.c` | Searches for an integer in an array using a comparison function. | <ul><li>[x] Completed</li></ul> |
| **3** | `3-main.c`, `3-op_functions.c`, `3-get_op_func.c`, `3-calc.h` | Programs a command-line calculator using function pointers and strict rules. | <ul><li>[x] Completed</li></ul> |
| **100** | `100-main_opcodes.c` | Prints the opcodes of its own main function in hexadecimal format. | <ul><li>[x] Completed</li></ul> |

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:
- What function pointers are and how to use them.
- What a function pointer exactly holds in memory.
- Where a function pointer points to in virtual memory.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`.
- All files will be compiled on **Ubuntu 20.04 LTS** using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All files should end with a new line.
- A `README.md` file at the root of the folder is mandatory.
- Code must use the **Betty style** (checked using `betty-style.pl` and `betty-doc.pl`).
- Global variables are not allowed.
- Maximum of 5 functions per file.
- Allowed standard library functions: `malloc`, `free`, and `exit`. (And `printf`/`atoi` where specified in Task 4).
- Include guards are required for all header files.