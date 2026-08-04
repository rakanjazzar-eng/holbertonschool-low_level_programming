# Low-Level Memory Analysis & Visual Maps

This report provides a low-level execution and memory lifetime analysis for `stack_example.c` and `aliasing_example.c`. It explicitly tracks stack frames, heap allocations, and pointer ownership while critically evaluating AI-generated explanations.

---

## 1. Stack Memory Behavior (`stack_example.c`)

### Execution Timeline & Memory States

#### State 1: Function Entry & Local Frame Setup
* **Execution Point:** Entry into the allocation helper function (e.g., `create_integer()`).
* **Stack State:** A new stack frame is pushed onto the call stack. The Stack Pointer (`RSP`) decrements to reserve memory for local variables.
* **Heap State:** Unaffected (No dynamic memory requested).

+------------------------------------+ <- Base Pointer (RBP)
| Return Address to main()           |
+------------------------------------+
| Local Var: val = 42                | [Addr: 0x7fff5fbff7bc]
+------------------------------------+ <- Stack Pointer (RSP)

#### State 2: Function Exit & Frame Invalidation
* **Execution Point:** Return statement execution and function exit.
* **Lifetime Constraint:** The scope of `val` terminates immediately. The function's stack frame is popped by incrementing `RSP`. The memory address `0x7fff5fbff7bc` is no longer reserved or safe to access.
* **Memory Anomaly:** Returning `&val` passes an unallocated stack address to `main()`, turning the receiving pointer into a **Dangling Pointer**.

#### State 3: Stack Collision & Use-After-Scope
* **Execution Point:** Call to subsequent functions (e.g., `print_something_else()`) followed by dereferencing the pointer.
* **Stack Overwrite:** The new function call reuses the stack memory area previously occupied by `create_integer()`. The value at `0x7fff5fbff7bc` is overwritten with new stack data.
* **Runtime Behavior:** Dereferencing the dangling pointer results in an **Invalid Read (Use-After-Scope)**, producing garbage values or Undefined Behavior (UB).

---

## 2. Pointer Aliasing & Heap Ownership (`aliasing_example.c`)

### Memory Lifetime & Pointer Ownership Tracking

| Pointer Variable | Memory Region | Memory Address | Ownership Role | Lifetime / Validity Status |
| :--- | :--- | :--- | :--- | :--- |
| `main_ptr` | Heap Segment | `0x5555555582a0` | Primary Allocator (`main`) | Valid until `free()` |
| `alias_ptr` | Heap Segment | `0x5555555582a0` | Borrowed Alias | Valid (Shares target address) |
| `ptr_a` (in func) | Heap Segment | `0x5555555582a0` | Deallocator | Invalidated via `free(ptr_a)` |
| `ptr_b` (in func) | Heap Segment | `0x5555555582a0` | Dangling Alias | **Invalid** (Refers to freed memory) |

### Memory Lifecycle Step-by-Step

1. **Dynamic Allocation:** `malloc(sizeof(int))` requests memory from the OS runtime heap, returning block address `0x5555555582a0`.
2. **Aliasing Creation:** `alias_ptr = main_ptr` copies the 64-bit address value. No new memory is allocated; both variables now point to the exact same bytes in the Heap.
3. **Deallocation:** Executing `free(ptr_a)` marks the heap block at `0x5555555582a0` as unallocated and returns it to the heap manager's free-list.
4. **Invalid Access (Use-After-Free):** Dereferencing `*ptr_b` attempts to read a deallocated heap block. Valgrind reports this as an `Invalid read of size 4`.
5. **Double Deallocation (Double Free):** Calling `free(alias_ptr)` later attempts to release an already freed chunk, causing a runtime crash (`glibc detected *** double free or corruption`).

---

## 3. AI Critique & Error Case Study

> **Objective:** Document and correct low-level memory reasoning errors produced by AI tools during program analysis.

### AI Prompt Tested
*"Explain what happens to the address returned by a C function when it returns a pointer to a local stack variable."*

### Misleading/Incorrect AI Explanation
> *"When a function returns a pointer to a local variable, C automatically resets the pointer to NULL upon function return to prevent invalid memory access."*

### Technical Critique of AI Inaccuracy
* **Why it is wrong:** Standard C compilers do not automatically zero out or assign `NULL` to pointers referencing expired stack frames. The returned pointer retains the literal hardware address (`0x7fff5fbff7bc`).
* **Actual Low-Level Behavior:** The CPU register holds the original stack frame memory address. However, because the stack pointer (`RSP`) has moved back during frame deallocation, that memory location is marked as available for future allocation. Accessing this raw address does not fail safely with a `NULL` check; instead, it reads corrupted stack data or causes silent memory corruption.

### Corrected Explanation
Returning `&val` leaves the pointer storing a valid-looking but legally invalid address (`0x7fff5fbff7bc`). The compiler does not modify the pointer value to `NULL`. When subsequent function calls push new stack frames, they overwrite the contents at that address. Dereferencing this pointer triggers an **Invalid Read / Use-After-Scope** vulnerability, yielding undefined behavior.

---

## 4. Deterministic Fault Summary

### `stack_example.c`
* **Fault Category:** Stack Lifetime Violation / Returning Address of Local Variable.
* **Causal Chain:** Stack frame creation → Function return (Frame popping without clearing pointer) → Pointer becomes dangling → Stack frame reuse by next function → Dereference causes Invalid Read (Use-After-Scope).

### `aliasing_example.c`
* **Fault Category:** Pointer Aliasing / Use-After-Free / Double Free.
* **Causal Chain:** Heap memory allocation → Address aliased across multiple pointers → Early deallocation via primary pointer → Secondary pointer dereferenced (Use-After-Free) → Secondary pointer deallocated (Double Free crash).