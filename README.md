# Red-Black Tree

## Overview

This project is an implementation of a Red-Black Tree in C++.

A Red-Black Tree is a self-balancing Binary Search Tree. It uses node colours and rotations to keep the tree balanced.

The current implementation stores integer values.

The project also includes an AVL Tree implementation used to compare the performance of the two self-balancing tree structures.

## Features

- Insert values
- Delete values
- Search for nodes
- Left and right rotations
- Automatic balancing after insertion
- Automatic balancing after deletion
- Print values in sorted order
- AVL Tree implementation for comparison
- GoogleTest unit tests
- Performance benchmarking

## Project Structure

```text
Red-Black-Tree-Implementation/
│
├── RedBlackTree/
│   ├── RedBlackTree.hpp
│   ├── RedBlackTree.cpp
│   └── main.cpp
│
├── AVLTree/
│   ├── AVLTree.hpp
│   └── AVLTree.cpp
│
├── tests/
│   ├── RedBlackTreeTest.cpp
│   └── AVLTreeTest.cpp
│
├── benchmark/
│   └── benchmark.cpp
│
├── CMakeLists.txt
├── README.md
└── .gitignore
```

## How to Compile

### Using CMake

Create the build directory:

```bash
mkdir build
cd build
```

Configure and build the project:

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

Run the Red-Black Tree program:

```bash
./redblacktree
```

## Running Tests

The project uses GoogleTest.

Run all tests with:

```bash
ctest --output-on-failure
```

Or run the test executable directly:

```bash
./tree_tests
```

## Running the Benchmark

Run:

```bash
./tree_benchmark
```

The benchmark compares the insertion and search performance of the Red-Black Tree and AVL Tree using the same input data.

The benchmark measures execution time in microseconds for different tree sizes.

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
```

## Performance Comparison

The empirical study compares the Red-Black Tree with an AVL Tree.

The results showed that for larger datasets, the Red-Black Tree performed better for insertion, while the AVL Tree performed better for searching.

For example, at 100,000 elements, the average results were approximately:

| Operation | Red-Black Tree | AVL Tree |
|---|---:|---:|
| Insertion | 16,409 µs | 21,119 µs |
| Search | 6,879 µs | 5,783 µs |

The results demonstrate the different balancing strategies of the two trees. Red-Black Trees use less strict balancing, while AVL Trees maintain a more strictly balanced structure.