Iterative Quicksort:
This repository contains an implementation of the Quicksort sorting algorithm in its iterative version, using an explicit stack to manage the calls that would normally be made recursively. The implementation aims to offer an alternative to recursion, which can be beneficial in contexts where the depth of the call stack is a concern, such as in systems with limited memory resources or in large datasets that can lead to stack overflows in a recursive implementation.

//

Project structure:
The project consists of three main files:

stack.h: Header file that defines the stack structure used to manage the sub-array indexes during the sorting process, as well as the signature of the stack manipulation functions and the iterative quicksort.
stack.c: Implementation of the functions defined in stack.h, including the stack creation and release functions, push and pop operations, and the quicksort partitioning and sorting logic.
main.c: User input file that allows you to specify the size and elements of the array to be sorted. This file also includes the call to the quickSortIterative function and the printout of the sorted array.

//

Features:
Iterative Quicksort: Implements the quicksort algorithm using a stack to avoid recursion.
Dynamic Data Input: Allows the user to specify the size and elements of the array at runtime.
Managed Memory: Use of dynamic memory allocation and release for the array of elements, ensuring efficient use of resources.

//

How to Compile and Run:
Compilation: Use the make command in the root directory of the project to compile the files.
Execution: After compilation, run the program with ./quicksort to start inserting the data and see the result of the sorting.
