# C - Variadic Functions

## Description
This project covers the concept of Variadic Functions in C language, exploring how to write functions that accept a variable number of arguments using standard macros like `va_start`, `va_arg`, and `va_end`.

## Tasks

| Task | File | Description | Status |
| :---: | --- | --- | --- |
| **0** | `0-sum_them_all.c` | Returns the sum of all its parameters. Returns 0 if `n == 0`. | <ul><li>[x] Completed</li></ul> |
| **1** | `1-print_numbers.c` | Prints numbers, followed by a new line. | <ul><li>[x] Completed</li></ul> |
| **2** | `2-print_strings.c` | Prints strings, followed by a new line. | <ul><li>[x] Completed</li></ul> |
| **3** | `3-print_all.c` | Prints anything based on a format specifier. | <ul><li>[x] Completed</li></ul> |
| **4** | `100-hello_world.asm` | Writes a 64-bit assembly program that prints `Hello, World` using the `write` syscall. | <ul><li>[x] Completed</li></ul> |

## Resources
* `stdarg.h`
* Variadic Functions in C
* `const` Keyword Qualifier

## Requirements
* **Allowed Editors:** `vi`, `vim`, `emacs`
* **Compiler:** `gcc` on Ubuntu 20.04 LTS using `-Wall -Werror -Wextra -pedantic -std=gnu89`
* **Code Style:** Betty style (`betty-style.pl` and `betty-doc.pl`)
* **Header File:** `variadic_functions.h` with include guards.
* **Allowed Macros:** `va_start`, `va_arg`, `va_end`.
* **Forbidden:** Global variables, standard print functions like `printf` or `puts` (inside required solution files except where allowed).
