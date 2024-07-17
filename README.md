# DSA Project: Binary Search Tree Implementation in C++
Implementation of a Binary Search Tree with basic operations including insertion, deletion, search, and traversals in C++

# DSA-Binary-Search-Tree

## Description

This project implements a Binary Search Tree (BST) in C++. The BST is a fundamental data structure that stores elements in a sorted manner, allowing efficient insertion, deletion, and lookup operations. This project includes the basic functionalities of a BST, such as insertion, searching, deletion, and different tree traversal methods.

## Features and Functionalities
1. **Node Structure:**
   - A `Node` structure representing each node in the BST, containing:
     - `int val`: The value of the node.
     - `Node* left`: Pointer to the left child.
     - `Node* right`: Pointer to the right child.

2. **Insertion:**
   - Function `insert(Node* root, int insertVal)`: Inserts a value into the BST while maintaining the BST properties.

3. **Searching:**
   - Function `search(Node* root, int searchVal)`: Searches for a value in the BST and returns `true` if found, otherwise `false`.

4. **Deletion:**
   - Function `deleteNode(Node* root, int deleteVal)`: Deletes a specified value from the BST, adjusting the tree to maintain BST properties.

5. **Traversals:**
   - Function `inorder(Node* root)`: Performs an inorder traversal (left, root, right) and prints the node values.
   - Function `preorder(Node* root)`: Performs a preorder traversal (root, left, right) and prints the node values.
   - Function `postorder(Node* root)`: Performs a postorder traversal (left, right, root) and prints the node values.

6. **Memory Management:**
   - Function `freeTree(Node* root)`: Frees the dynamically allocated memory to avoid memory leaks.

## Example Usage
1. The user inputs the number of nodes and their values to build the BST.
2. The program displays the inorder, preorder, and postorder traversals of the BST.
3. The user can delete a node by specifying its value.
4. The program then displays the traversals of the BST after deletion.

### Input/Output
