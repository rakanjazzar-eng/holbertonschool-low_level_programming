# C - Hash tables

## Description
This project covers the concepts and implementation of Hash Tables in C programming language. It includes understanding hash functions (djb2 algorithm), handling collisions using chaining (singly linked lists), dynamic memory management, and analyzing the performance and trade-offs of hash tables compared to other data structures.

## Tasks

| Task | File | Description | Status |
| :---: | --- | --- | :---: |
| **0** | `0-hash_table_create.c` | Writes a function that creates a hash table with a specified size. | <ul><li>[x] Completed</li></ul> |
| **1** | `1-djb2.c` | Implements the djb2 algorithm to generate a hash key from a string. | <ul><li>[x] Completed</li></ul> |
| **2** | `2-key_index.c` | Gives the index of a key based on the hash code and table size. | <ul><li>[x] Completed</li></ul> |
| **3** | `3-hash_table_set.c` | Adds or updates an element (`key`/`value` pair) in the hash table with collision handling (chaining). | <ul><li>[x] Completed</li></ul> |
| **4** | `4-hash_table_get.c` | Retrieves a value associated with a key from the hash table. | <ul><li>[x] Completed</li></ul> |
| **5** | `5-hash_table_print.c` | Prints a hash table in Python dictionary-like format (`{'key': 'value'}`). | <ul><li>[x] Completed</li></ul> |
| **6** | `6-hash_table_delete.c` | Deletes a hash table and frees all associated memory (nodes, keys, values, table). | <ul><li>[x] Completed</li></ul> |
| **100** | `100-sorted_hash_table.c` | *(Advanced)* Implements a PHP-like sorted hash table (`shash_table_t`) using a doubly linked list to preserve order. | <ul><li>[ ] Optional</li></ul> |

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:
- What is a hash function and what makes a good hash function.
- What is a hash table, how it works, and how to use it.
- What is a collision and the main ways of dealing with collisions (specifically Chaining).
- What are the advantages and drawbacks of using hash tables.
- Common use cases of hash tables.

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`.
- All files will be compiled on **Ubuntu 20.04 LTS** using `gcc` with options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All files must end with a new line.
- A `README.md` file at the root of the folder of the project is mandatory.
- Code must use the **Betty style** (checked using `betty-style.pl` and `betty-doc.pl`).
- Global variables are not allowed.
- Maximum of 5 functions per file.
- All header files must be include guarded (`hash_tables.h`).