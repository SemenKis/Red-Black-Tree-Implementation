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

    std::cout << "Insert the element: " << key << std::endl;

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

    balance(newNode);
}

void RedBlackTree::leftRotate(Node* node) {

    std::cout << "leftRotate() is called" << std::endl;

    Node* rightChild = node->right;

    node->right = rightChild->left;

    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    }
    else if (node == node->parent->left) {
        node->parent->left = rightChild;
    }
    else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void RedBlackTree::rightRotate(Node* node) {

    std::cout << "rightRotate() is called" << std::endl;

    Node* leftChild = node->left;

    node->left = leftChild->right;

    if (leftChild->right != nullptr) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    }
    else if (node == node->parent->left) {
        node->parent->left = leftChild;
    }
    else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void RedBlackTree::balance(Node* node) {

    std::cout << "Balance the tree" << std::endl;

    while (node != root &&
           node->parent != nullptr &&
           node->parent->color == RED) {

        Node* parent = node->parent;
        Node* grandparent = parent->parent;

        // Parent is the left child of the grandparent
        if (parent == grandparent->left) {

            Node* uncle = grandparent->right;

            // Case 1: Uncle is red
            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                node = grandparent;
            }
            else {

                // Case 2: Node is the right child
                if (node == parent->right) {
                    node = parent;
                    leftRotate(node);

                    parent = node->parent;
                    grandparent = parent->parent;
                }

                // Case 3: Node is the left child
                parent->color = BLACK;
                grandparent->color = RED;

                rightRotate(grandparent);
            }
        }

        // Parent is the right child of the grandparent
        else {

            Node* uncle = grandparent->left;

            // Case 1: Uncle is red
            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;

                node = grandparent;
            }
            else {

                // Case 2: Node is the left child
                if (node == parent->left) {
                    node = parent;
                    rightRotate(node);

                    parent = node->parent;
                    grandparent = parent->parent;
                }

                // Case 3: Node is the right child
                parent->color = BLACK;
                grandparent->color = RED;

                leftRotate(grandparent);
            }
        }
    }

    root->color = BLACK;
}
