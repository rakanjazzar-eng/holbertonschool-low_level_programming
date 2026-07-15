# Simple Calculator

## Description

A terminal-based interactive calculator written in C.

The program displays a menu, allows the user to select an operation, performs the calculation, displays the result, and continues running until the user chooses to quit.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

## Running

```bash
./calculator
```

## Supported Operations

* Addition
* Subtraction
* Multiplication
* Division

## Numeric Behavior

The calculator uses the `float` data type for all numeric operations.

This allows the program to work with both whole numbers and decimal values. For example:

* `5 + 3` → `8.000000`
* `5.5 + 3.2` → `8.700000`

All results are displayed using the `%f` format specifier.

## Input

* Menu options are read using `scanf`.
* Numeric operands are read using `scanf`.
* Operands may be entered as whole numbers or decimal values.

## Division by Zero

If the second operand is zero during division, the program prints:

```text
Error: division by zero
```

and the operation is not performed.

## Known Limitations

The mandatory implementation validates menu choices only.

Handling arbitrary non-numeric input is outside the scope of the mandatory project requirements.