# Red-Black Tree

## Overview

This project is an implementation of a Red-Black Tree in C++.

A Red-Black Tree is a self-balancing Binary Search Tree. It uses node colours and rotations to keep the tree balanced.

The current implementation stores integer values.

## Features

- Insert values
- Delete values
- Search for nodes
- Left and right rotations
- Automatic balancing after insertion
- Automatic balancing after deletion
- Print values in sorted order

## Project Structure

- `RedBlackTree.hpp` - Red-Black Tree class and Node definition
- `RedBlackTree.cpp` - implementation of the tree
- `main.cpp` - testing and examples

## Example

```cpp
RedBlackTree tree;

tree.insert(10);
tree.insert(5);
tree.insert(15);
tree.insert(4);
tree.insert(8);

tree.print();

tree.remove(8);
tree.print();