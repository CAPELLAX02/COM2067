# Trees

## Introduction

A **tree** is a hierarchical data structure consisting of nodes connected by edges. The topmost node is called the root, and each node can have child nodes. Trees are widely used in computer science due to their ability to represent hierarchical relationships and support efficient operations such as searching, insertion, and deletion.

## Types of Trees

### 1. General Tree
A tree in which nodes can have an arbitrary number of children.

### 2. Binary Tree
A tree where each node has at most two children, commonly referred to as the left and right child.

- **Applications**:
  - Expression evaluation (e.g., parsing arithmetic expressions).
  - Representing binary heap in priority queues.

### 3. Binary Search Tree (BST)
A binary tree with the property that the value of each node in the left subtree is less than the parent node, and the value in the right subtree is greater.

- **Operations**:
  - **Insertion**: Average O(log n).
  - **Deletion**: Average O(log n).
  - **Search**: Average O(log n).

### 4. Self-Balancing Trees
These trees maintain a balanced structure to ensure operations are efficient even in the worst case.

#### AVL Tree
- Balances the tree by ensuring the height difference (balance factor) between the left and right subtrees is at most 1.
- Guarantees O(log n) operations for insertion, deletion, and search.

#### Red-Black Tree
- Ensures balance by following specific rules such as red-black coloring of nodes and rotation-based balancing.

### 5. Heap (Binary Heap)
A special binary tree used in priority queues. It can be:
- **Min-Heap**: Parent node ≤ child nodes.
- **Max-Heap**: Parent node ≥ child nodes.

### 6. B-Tree
A self-balancing tree often used in databases and file systems. It is optimized for systems that read and write large blocks of data.

### 7. Trie (Prefix Tree)
A tree used for storing and searching strings, especially in text prediction and dictionary applications.

### 8. Segment Tree
Used for range queries, such as finding the sum or minimum of elements in a specific range of an array.

## Applications

- **Hierarchical data representation**: File systems, organizational charts.
- **Efficient searching and sorting algorithms**: Binary search trees, AVL trees.
- **Memory management**: Binary heaps.
- **Databases and indexing**: B-Trees.
- **Text processing**: Tries for prefix matching and auto-completion.

## Goals of This Repository

1. **Learn and implement various tree structures in C**:
    - Start from basic binary trees.
    - Progress to advanced structures like AVL, Red-Black Trees, and Tries.
2. **Understand and demonstrate common tree operations**:
    - Insertion, deletion, traversal, and search.
3. **Provide clear explanations and visualizations** for each tree type.

## Structure of the Repository

- `BinaryTree/`: Basic binary tree implementation with traversal methods (in-order, pre-order, post-order).
- `BinarySearchTree/`: Implementation of insertion, deletion, and search in BST.
- `AVLTree/`: Self-balancing AVL tree with rotation logic.
- `RedBlackTree/`: Red-black tree implementation.
- `Heap/`: Binary heap (min-heap and max-heap) structure.
- `BTree/`: Implementation of B-Tree for database-like scenarios.
- `Trie/`: Prefix tree implementation for string operations.
- `SegmentTree/`: Implementation for range query problems.

---

## How to Run

Each folder contains C source files and a Makefile for compilation. Follow these steps:

1. Navigate to the desired tree folder:
   ```bash
   cd BinaryTree
   ```
   
2. Compile the desired C program:
    ```bash
    gcc DesiredTreeProgram.c -o DesiredTreeProgram
    ```

3. Run the executable:
    ```bash
    ./DesiredTreeProgram
    ```

## Feature Work
- Add graphical visualizations for tree operations.
- Include more complex tree structures like Fenwick Trees and Splay Trees.
- Expand with real-world examples and applications.