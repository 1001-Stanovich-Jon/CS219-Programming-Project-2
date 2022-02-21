# CS219 Programming Assignment 2

Due 3 March 2022.

## Student Information
Jonathan Jake Stanovich Rubalcava - jonstanovich@nevada.unr.edu

Github Repository for My Assignment - https://github.com/1001-Stanovich-Jon/CS219-Programming-Project-2
# Project 2 Overview

The first project had us develop some basic code that could read an input file with lines of text of the form

`ADD OPERAND_1 OPERAND_2`

and it would display this input along with the addition of the operands. Project 2 extends the functionality of the first project, and will include the following operations:

1. ADD - Takes in two operands, and adds them.
2. AND - Takes in two operands, and performs a bitwise AND between them.
3. ASR - Takes in one operand, and performs an arithmetic shift right on it.
4. LSR - Takes in one operand, and perfroms a logic shift right on it.
5. LSL - Takes in one operand, and performs a logic shift left on it.
6. NOT - Takes in one operand, and performs a bitwise NOT.
7. ORR - Takes in two operands, and performs a bitwise OR between them.
8. SUB - Takes in two operands, and subtracts the second operand from the first.
9. XOR - Takes in two operands, and performs a bitwise XOR between them.

In each of the above cases, the operands and operations specified in the input file are displayed to the screen, along with the output of the operation.

#INPUT FILE REQUIREMENTS

Any operation that expects **two inputs** needs to be formatted as:
`OPERATION OPERAND_1 OPERAND_2`

Any operation that expects **one input** needs to be formatted as:
`OPERATION OPERAND_1`

Where:
- `OPERATION` is one of the nine 3-letter operations from the list above
- `OPERAND_1` and `OPERAND_2` are 32-bit hex numbers of the form `0xXXXXXXXX`
- Each operation must be on a separate line.

If two operands are given to an operation expecting one, or one operand is given to an opereation expecting two, an error will result. Note that it does not check if there are more than 2 operands, so please be nice.


---

## Installation
Install Ubuntu or the windows subsystem for linux.

---

## Usage example
Navigate to build folder. To run with an input file of your choice simply use:
```sh
> make
> ./main <input file name>
> make clean
```

To run with my input file, which is is PP2_input.txt, use
```sh
> make
> ./main PP2_input.txt
> make clean
```

---

## Development setup
I'm using WSL, which comes default with GNU Make (I have version 4.2.1). 