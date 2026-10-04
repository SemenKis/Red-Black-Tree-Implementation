#include <iostream>
#include "RedBlackTree.hpp"

int main() {
    RedBlackTree tree;

    // tree.insert(10);
    // tree.insert(5);
    // tree.insert(15);
    // tree.insert(3);
    // tree.insert(7);

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(16);
    tree.insert(4);
    tree.insert(8);

    std::cout << "Tree elements: ";
    tree.print();

    tree.remove(8);

    std::cout << "Tree elements after deletion: ";
    tree.print();

    RedBlackTree tree_2;

    tree_2.insert(10);
    tree_2.insert(5);
    tree_2.insert(3);

    std::cout << "Tree_2 elements: ";
    tree_2.print();
    
    return 0;
}