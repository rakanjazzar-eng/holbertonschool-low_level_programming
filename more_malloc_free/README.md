# C - More malloc, free

## Description
This project focuses on advanced dynamic memory allocation in C using `malloc`, `free`, and controlling process termination with `exit`. It reinforces memory safety, handling dynamic arrays, and adhering to strict memory constraints without relying on standard library functions like `calloc` or `realloc`.

## Task List

| Task | File | Description | Status |
| :---: | --- | --- | --- |
| **0** | `0-malloc_checked.c` | Allocates memory using `malloc` and terminates process with status 98 if it fails. | <ul><li>[x] Completed</li></ul> |
| **1** | `1-string_nconcat.c` | Concatenates two strings by taking `s1` and the first `n` bytes of `s2`. | <ul><li>[x] Completed</li></ul> |
| **2** | `2-calloc.c` | Allocates memory for an array using `malloc` and initializes all bytes to zero. | <ul><li>[x] Completed</li></ul> |
| **3** | `3-array_range.c` | Creates an array of integers containing all values from `min` to `max` (inclusive). | <ul><li>[x] Completed</li></ul> |
| **100** | `100-realloc.c` | Reallocates a memory block using `malloc` and `free`. | <ul><li>[ ] In Progress</li></ul> |
| **101** | `101-mul.c` | Multiplies two positive big numbers passed as command line arguments. | <ul><li>[ ] In Progress</li></ul> |

## Compilation & Requirements
* Compiled on **Ubuntu 20.04 LTS** using `gcc`
* Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
* Code style: **Betty style** (`betty-style.pl` & `betty-doc.pl`)
* Allowed standard library functions: `malloc`, `free`, `exit`, and `_putchar`
