#include <iostream>
#include <algorithm>

#include "AVLTree.hpp"


AVLTree::AVLTree()
    : root(nullptr) {
}


AVLTree::~AVLTree() {
    destroy(root);
}


void AVLTree::destroy(Node* node) {
    if (node == nullptr) {
        return;
    }

    destroy(node->left);
    destroy(node->right);

    delete node;
}


bool AVLTree::empty() const {
    return root == nullptr;
}


int AVLTree::height(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}


int AVLTree::getBalance(Node* node) const {
    if (node == nullptr) {
        return 0;
    }

    return height(node->left) -
           height(node->right);
}


AVLTree::Node* AVLTree::rightRotate(Node* node) {
    Node* leftChild = node->left;
    Node* subtree = leftChild->right;

    leftChild->right = node;
    node->left = subtree;

    node->height =
        1 + std::max(
            height(node->left),
            height(node->right)
        );

    leftChild->height =
        1 + std::max(
            height(leftChild->left),
            height(leftChild->right)
        );

    return leftChild;
}


AVLTree::Node* AVLTree::leftRotate(Node* node) {
    Node* rightChild = node->right;
    Node* subtree = rightChild->left;

    rightChild->left = node;
    node->right = subtree;

    node->height =
        1 + std::max(
            height(node->left),
            height(node->right)
        );

    rightChild->height =
        1 + std::max(
            height(rightChild->left),
            height(rightChild->right)
        );

    return rightChild;
}


void AVLTree::insert(int key) {
    root = insert(root, key);
}


AVLTree::Node* AVLTree::insert(
    Node* node,
    int key) {

    // Normal BST insertion
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left =
            insert(node->left, key);
    }
    else if (key > node->key) {
        node->right =
            insert(node->right, key);
    }
    else {
        // Ignore duplicate values
        return node;
    }


    // Update height
    node->height =
        1 + std::max(
            height(node->left),
            height(node->right)
        );


    int balance = getBalance(node);


    // Case 1: Left Left
    if (balance > 1 &&
        key < node->left->key) {

        return rightRotate(node);
    }


    // Case 2: Right Right
    if (balance < -1 &&
        key > node->right->key) {

        return leftRotate(node);
    }


    // Case 3: Left Right
    if (balance > 1 &&
        key > node->left->key) {

        node->left =
            leftRotate(node->left);

        return rightRotate(node);
    }


    // Case 4: Right Left
    if (balance < -1 &&
        key < node->right->key) {

        node->right =
            rightRotate(node->right);

        return leftRotate(node);
    }


    return node;
}


AVLTree::Node* AVLTree::minimum(
    Node* node) const {

    Node* current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}


void AVLTree::remove(int key) {
    root = remove(root, key);
}


AVLTree::Node* AVLTree::remove(
    Node* node,
    int key) {

    if (node == nullptr) {
        return node;
    }


    // Normal BST deletion
    if (key < node->key) {
        node->left =
            remove(node->left, key);
    }
    else if (key > node->key) {
        node->right =
            remove(node->right, key);
    }
    else {

        // No child or one child
        if (node->left == nullptr ||
            node->right == nullptr) {

            Node* child =
                node->left != nullptr
                ? node->left
                : node->right;

            if (child == nullptr) {
                delete node;
                return nullptr;
            }

            Node* oldNode = node;
            node = child;

            delete oldNode;
        }

        // Two children
        else {
            Node* successor =
                minimum(node->right);

            node->key = successor->key;

            node->right =
                remove(
                    node->right,
                    successor->key
                );
        }
    }


    if (node == nullptr) {
        return node;
    }


    // Update height
    node->height =
        1 + std::max(
            height(node->left),
            height(node->right)
        );


    int balance = getBalance(node);


    // Left Left
    if (balance > 1 &&
        getBalance(node->left) >= 0) {

        return rightRotate(node);
    }


    // Left Right
    if (balance > 1 &&
        getBalance(node->left) < 0) {

        node->left =
            leftRotate(node->left);

        return rightRotate(node);
    }


    // Right Right
    if (balance < -1 &&
        getBalance(node->right) <= 0) {

        return leftRotate(node);
    }


    // Right Left
    if (balance < -1 &&
        getBalance(node->right) > 0) {

        node->right =
            rightRotate(node->right);

        return leftRotate(node);
    }


    return node;
}


bool AVLTree::contains(int key) const {
    return search(root, key);
}


bool AVLTree::search(
    Node* node,
    int key) const {

    while (node != nullptr) {

        if (key == node->key) {
            return true;
        }

        if (key < node->key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    return false;
}


void AVLTree::printInOrder(
    Node* node) const {

    if (node == nullptr) {
        return;
    }

    printInOrder(node->left);

    std::cout << node->key << " ";

    printInOrder(node->right);
}


void AVLTree::print() const {
    printInOrder(root);

    std::cout << std::endl;
}