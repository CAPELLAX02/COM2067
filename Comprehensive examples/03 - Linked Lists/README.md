# Linked Lists

## Introduction

A **Linked List** is a dynamic data structure that consists of nodes, where each node stores data and a reference (pointer) to the next node in the sequence. Linked lists are used in scenarios where dynamic memory allocation is needed, and frequent insertions and deletions are required.

## Purpose and Usage

-   Linked lists allow for efficient memory management and dynamic resizing, unlike arrays which are fixed in size.
-   They are useful for implementing stacks, queues, and other dynamic structures.
-   Linked lists offer efficient insertion and deletion operations, particularly at the beginning or middle of the list.

## Types of Linked Lists

### 1. **Singly Linked List**

-   Each node points to the next node in the sequence.
-   Traversal is only possible in one direction.
-   Key operations include:
    -   **Insertion** at the head, tail, or specific positions.
    -   **Deletion** of specific nodes or by position.
    -   **Reversal** of the list.
    -   **Length Calculation** and other utility operations.

### 2. **Doubly Linked List**

-   Each node points to both the previous and the next node.
-   Traversal is possible in both directions (forward and backward).
-   Key operations include:
    -   **Insertion** at the head, tail, or specific positions.
    -   **Deletion** by value or position.
    -   **Bidirectional traversal** and **Reversal**.

### 3. **Circular Linked List**

-   The last node points back to the head, creating a circular structure.
-   Traversal continues from the last node back to the first.
-   Key operations include:
    -   **Circular traversal** of nodes.
    -   **Insertion** and **Deletion** in a circular fashion.

## Comprehensive Examples

### Singly Linked List

1. **Basic Operations**:
    - Insertion at the head and tail.
    - Deletion by value.
    - Traversal and display.
    - Reversal of the list.
2. **Advanced Examples**:
    - **Length Calculation**: Calculate the length of the list.
    - **Detecting Loops**: Check if a loop exists in the list.
    - **Merging Two Lists**: Merge two linked lists into one.
    - **Sorting a Linked List**: Sort the elements of the linked list.

### Doubly Linked List

1. **Basic Operations**:
    - Insertion at head and tail.
    - Deletion by value.
    - Forward and backward traversal.
2. **Advanced Examples**:
    - **Reversal**: Reverse the doubly linked list.
    - **Sorting**: Sort the elements of the list.
    - **Insertion at a specific position**.

### Circular Linked List

1. **Basic Operations**:
    - Circular traversal of nodes.
    - Insertion and deletion in a circular fashion.
2. **Advanced Examples**:
    - **Length Calculation**: Count the number of nodes.
    - **Detecting Loops**: Check if the circular list contains any unintended loops.
