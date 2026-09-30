#include <iostream>
#include "RedBlackTree.hpp"

void RedBlackTree::printInOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }

    printInOrder(node->left);

    std::cout << node->key << " ";

    printInOrder(node->right);
}

void RedBlackTree::print() const {
    printInOrder(root);
    std::cout << std::endl;
}

RedBlackTree::RedBlackTree()
    : root(nullptr) {
}

bool RedBlackTree::empty() const {
    return root == nullptr;
}

void RedBlackTree::insert(int key) {
    Node* newNode = new Node(key);

    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr) {
        parent = current;

        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (parent == nullptr) {
        root = newNode;
    } else if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}