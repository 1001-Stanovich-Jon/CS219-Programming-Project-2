# CS219 Programming Assignment 1

Due 28 January 2022.

## Student Information
Jonathan Jake Stanovich Rubalcava - jonstanovich@nevada.unr.edu

Github Repository for My Assignment - https://github.com/1001-Stanovich-Jon/CS219-Programming-Assignment-1

# Project 1 Overview
At the lowest level, computers handle instructions by using electrical signals. Binary can be used to represent these signals, and the lowest level instructions can be described using binary sequences. This is dependent on the machine being used. Higher level languages were developed to lessen the burden on programmers, and provide a more readable and efficient way to develop instructions. 

As memory and speed have improved, the need to write in lower level languages has decreased, as labor costs are more of a worry than efficiency. However, to truly (or better) understand how computers work it is useful to examine what is happening at these lower levels. The purpose of this project is to analyze how assembly language is structured, and to write a program in C/C++ that will read instructions written in assembly language and perform them.

This first project will focus on performing addition on two operands. To do this, a program will be written in C/C++ that will read from an input file, parse the lines, and perform a specified operation. We begin with instructions following the form below, where both operands are given as hexadecimal numbers. The sum will then be displayed to the terminal.

`ADD OPERAND_1 OPERAND_2`

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

So for this project it would be
```sh
> make
> ./main Programming-Project-1.txt
> make clean
```


---

## Development setup
I'm using WSL, which comes default with GNU Make (I have version 4.2.1). 