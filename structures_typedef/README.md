# C - Structures, typedef

## Description
This project covers the fundamentals of C structures (`struct`) and type aliases (`typedef`). It focuses on how to group variables of different data types into a single compound type, create reusable type definitions, allocate and manage dynamic memory for structures, and clean up resources to prevent memory leaks using `valgrind`.

## Project Structure & Task Status

| Task | File | Description | Status |
| :---: | --- | --- | --- |
| **0** | `dog.h` | Define a new type `struct dog` with elements: `name`, `age`, and `owner`. | <ul><li>[x] Completed</li></ul> |
| **1** | `1-init_dog.c` | Write a function that initializes a variable of type `struct dog`. | <ul><li>[x] Completed</li></ul> |
| **2** | `2-print_dog.c` | Write a function that prints a `struct dog`. | <ul><li>[x] Completed</li></ul> |
| **3** | `dog.h` | Define a new type `dog_t` as a new name for `struct dog`. | <ul><li>[x] Completed</li></ul> |
| **4** | `4-new_dog.c` | Write a function that creates a new dog with dynamic memory and full string copies. | <ul><li>[x] Completed</li></ul> |
| **5** | `5-free_dog.c` | Write a function that frees dogs and their allocated inner memory. | <ul><li>[x] Completed</li></ul> |

## Learning Objectives
By the end of this project, you should be able to explain:
- What structures are, when, why, and how to use them.
- How to use `typedef` to simplify code syntax.
- How to handle dynamic allocation (`malloc`) and freeing (`free`) for structures and their members.

## Requirements
- **Allowed editors:** `vi`, `vim`, `emacs`
- **Compilation:** All files compiled on Ubuntu 20.04 LTS using `gcc` with flags:  
  `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Code Style:** All files formatted strictly to the **Betty style** (`betty-style.pl` and `betty-doc.pl`).
- **Header Files:** All header files must be include guarded (`#ifndef DOG_H ... #endif`).
- **Memory Check:** Zero leaks using `valgrind`.
