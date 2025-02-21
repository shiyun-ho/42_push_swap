# Push Swap - Technical Requirements

## Table of Contents
- [Push Swap - Technical Requirements](#push-swap---technical-requirements)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Project Objectives](#project-objectives)
  - [Technical Requirements](#technical-requirements)
  - [Evaluation Criteria](#evaluation-criteria)
  - [Personal Thought Process](#personal-thought-process)
    - [Understanding the Problem](#understanding-the-problem)
    - [Algorithm Design](#algorithm-design)
    - [Implementation Details](#implementation-details)
    - [Testing Strategy](#testing-strategy)
    - [Issues](#issues)

---

## Introduction
Push Swap is a project designed to test the ability to sort data efficiently using a set of predefined operations. The goal is to use as few operations as possible while adhering to strict requirements.

---

## Project Objectives
1. Create a program that sorts a stack of integers using two stacks and a limited set of operations.
2. Optimize the number of operations required for sorting.
3. Demonstrate a clear understanding of sorting algorithms and stack manipulation.

---

## Technical Requirements
- **Stacks**:
  - Two stacks must be used: `stack_a` (input stack) and `stack_b` (auxiliary stack).
- **Operations**:
  - `sa` (swap): Swap the first two elements of `stack_a`.
  - `sb` (swap): Swap the first two elements of `stack_b`.
  - `ss` (swap): Perform `sa` and `sb` simultaneously.
  - `pa` (push): Push the top element from `stack_b` to `stack_a`.
  - `pb` (push): Push the top element from `stack_a` to `stack_b`.
  - `ra` (rotate): Shift all elements of `stack_a` up by one.
  - `rb` (rotate): Shift all elements of `stack_b` up by one.
  - `rr` (rotate): Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate): Shift all elements of `stack_a` down by one.
  - `rrb` (reverse rotate): Shift all elements of `stack_b` down by one.
  - `rrr` (reverse rotate): Perform `rra` and `rrb` simultaneously.
- **Input**:
  - The program should accept a list of integers to sort.
  - Input validation must be performed to ensure only unique integers are accepted.
- **Output**:
  - A sequence of operations that sorts the stack.
  - The number of operations should be minimized.

---

## Evaluation Criteria
1. **Correctness**:
   - The output must correctly sort the integers.
2. **Efficiency**:
   - Minimize the number of operations used.
   - Algorithmic efficiency will be a major factor.
3. **Code Quality**:
   - Clean, readable, and maintainable code.
   - Proper handling of edge cases.
4. **Documentation**:
   - Clear explanations of the implemented algorithm and design choices.
5. **Testing**:
   - Include test cases that validate the solution for various input sizes and scenarios.

---

## Personal Thought Process

### Understanding the Problem
- **Questions to Consider**:
  - What are the constraints on input size?
  - What is the most efficient sorting algorithm that can be adapted to this problem?
- **Initial Observations**:
  - Sorting requires an understanding of stack operations.
  - Analyzing trade-offs between different sorting approaches is crucial.

### Algorithm Design
- **Approaches Explored**:
  - Evaluating bubble sort, quick sort, and insertion sort for adaptability.
  - Using divide-and-conquer techniques for larger stacks.
- **Challenges**:
  - Handling edge cases, e.g., already sorted input, reverse sorted input.
  - Balancing time complexity and operation count.

### Implementation Details
- **Plan**:
  - Write helper functions for each operation.
  - Implement a main sorting algorithm to generate the operation sequence.
- **Tools**:
  - Data structures: arrays or linked lists for stacks.
  - Language features to simplify operations.

### Testing Strategy
- **Test Cases**:
  - Small input sizes (e.g., 3 or 5 elements).
  - Larger input sizes with random integers.
  - Edge cases (e.g., empty stack, single element).
- **Tools**:
  - Write unit tests for individual operations.
  - Stress test with large data sets to ensure efficiency.

### Issues
- **Parsing**
  -  ./push_swap 123a
  -  ./push_swap #1
  -  ./push_swap #2
  -  ./push_swap #2 3 4
  -  ./push_swap +1+
  -  ./push_swap "3 2 1" [To resolve later]
  -  Fix atol: Check if_digit throughout the whole char[]
  -  Double free() detected for some inputs which violate conditions

- **Thought Process**
  - Bug: Double free() detected in instances where values are duplicated/ values exceed definition of int
    - After reviewing the code in `push_swap.c`, it seems like the double free comes from two sources:
      - Additional free(duplicate_check_array())
      - handle_error() not exiting directly
      - handle_error() not called for other functions which check for invalid input
  - Bug: Non digit characters are not parsed accurately. Rather than exiting the function entirely, non digit characters are not handled properly
    - Just realised that special characters such as `#` and `$` are characters unique to bash and used for interpretation. 
    - Modifications worked with `@` and `%` as they are non unique characters to shell. 
  - Feature: Sort Five Elements
    - After reflecting on the algorithm of sorting three elements - which was a twist on the sorting network - I attempted to:
      - Decided that the baseline algorithm could be:
        1. Find top two largest linked list nodes in linked list. 
        2. Shift both of them to temporary stack, `stack_b`.
        3. Sort the remaining elements using `sort_three_elements`. 
        4. Push top two elements back to `stack_a`.  
      - Utilise a sorting algorithm which introduces the use of `sort_three_elements` with pushing of top two largest nodes. 
      - Problems faced:
        1. At first, I've wanted to use BST to find top two largest nodes. 
        2. Decided perhaps it was too complex for me to introduce it here. 
  - Bug: Issues with pushing elements off stack
    - Found issues with pushing elements off the stack as my order of deassociationg was wrong
  - Bug: Issues with actions of swapping elements based on position after refactoring
  - Bug: 
  ```
  ARG="2 3 1"; ./push_swap $ARG | ./checker_linux $ARG
    KO
  ARG="6 8 1"; ./push_swap $ARG | ./checker_linux $ARG
    KO
  ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
    OK
  ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
    OK
  ARG="1 7 8"; ./push_swap $ARG | ./checker_linux $ARG
    OK
  ``
  - Bug: 
  ```
   ~/Documents/circle 2/42_push_swap  on v2_fix !3 ?65  ARG="1 2" | ./push_swap $ARG
      Counted no in quoted arg: 4
      Size: 3
      Before sort...
      >>> stack_a:
      2
      3
      1
      rra

    ~/Documents/circle 2/42_push_swap  on v2_fix !3 ?65  ./push_swap " 1 2"          
      Counted no in quoted arg: 3
      Size: 2
      Before sort...
      >>> stack_a:
      1
      2
  ```
  - Bug: Original stack in stack_a was modified during quick sort
    - Will need to make a copy of the stack for quick sort
    - Assign the new rank to the original stack_a 
    - Resolved by copying new stack, and assigning new ranks to stack_a by assigning ranks from new stack to old
    
