# Push Swap - Technical Requirements

## Table of Contents
- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Technical Requirements](#technical-requirements)
- [Evaluation Criteria](#evaluation-criteria)
- [Personal Thought Process](#personal-thought-process)
  - [Understanding the Problem](#understanding-the-problem)
  - [Algorithm Design](#algorithm-design)
  - [Implementation Details](#implementation-details)
  - [Testing Strategy](#testing-strategy)

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

---
