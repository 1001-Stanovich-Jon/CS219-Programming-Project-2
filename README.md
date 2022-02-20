# CS219 Programming Assignment 2

Due 1 March 2022.

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

---

## Installation
Install Linux or the windows subsystem.

---

## Usage example
Navigate to build folder
```sh
> make
> ./main <input file name>
> make clean
```

For this project the input file is PP2_input.txt, so use
```sh
> make
> ./main PP2_input.txt
> make clean
```


---

## Development setup
I'm using WSL, which comes default with GNU Make (I have version 4.2.1). 