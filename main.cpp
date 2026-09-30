#include <iostream>
#include "RedBlackTree.hpp"

int main() {
    RedBlackTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    std::cout << "Tree elements: ";
    tree.print();
    
    return 0;
}