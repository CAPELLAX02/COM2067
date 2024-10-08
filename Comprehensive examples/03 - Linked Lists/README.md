# Linked Lists

## Introduction

A **linked list** is a linear data structure where elements are stored in nodes. Each node contains two parts: the data and a pointer to the next node. Linked lists are dynamic, meaning they can grow and shrink in size as needed. Unlike arrays, linked lists do not require a contiguous block of memory, making them efficient for insertion and deletion operations.

## Purpose and Usage

-   Linked lists are used in scenarios where dynamic memory allocation is necessary.
-   They allow efficient insertion and deletion, especially at the beginning or in the middle of the list.
-   They are commonly used to implement other data structures such as stacks, queues, and hash tables.

## Types of Linked Lists

-   **Singly Linked List**: Each node points to the next node. It allows traversal in one direction.
-   **Doubly Linked List**: Each node points to both the next and the previous node, enabling traversal in both directions.
-   **Circular Linked List**: In a circular linked list, the last node points back to the head, creating a circular structure.

## Key Operations

-   **Insertion**: Add elements at the head, tail, or a specific position.
-   **Deletion**: Remove elements from the head, tail, or a specific position.
-   **Traversal**: Visit all nodes in the list to access data.
-   **Search**: Find a specific element in the list.
-   **Reversal**: Reverse the order of the elements in the list.
-   **Length Calculation**: Count the number of elements in the list.

## Implementations and Examples

### 1. **Singly Linked List**

-   Insertion at the head, tail, or a specific position.
-   Deletion from the head, tail, or a specific position.
-   Searching for an element.
-   Reversing the list.

### 2. **Doubly Linked List**

-   Bidirectional traversal.
-   Insertion and deletion from both ends.
-   Searching and reversing.

### 3. **Circular Linked List**

-   Traversal in a circular manner.
-   Insertion and deletion in a circular fashion.

### 4. **Advanced Examples**

-   Implementing a stack using a linked list.
-   Implementing a queue using a linked list.
-   Detecting and removing cycles (loops) in linked lists.
