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

    // std::cout << "Insert the element: " << key << std::endl;

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

    // std::cout << "leftRotate() is called" << std::endl;

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

    // std::cout << "rightRotate() is called" << std::endl;

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

    // std::cout << "Balance the tree" << std::endl;

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

void RedBlackTree::fixRulesAfterRemoval(Node* node, Node* parent) {
    while (node != root &&
           (node == nullptr || node->color == BLACK)) {

        if (parent == nullptr) {
            break;
        }

        // node is the left child
        if (node == parent->left) {
            Node* brother = parent->right;

            if (brother == nullptr) {
                node = parent;
                parent = node->parent;
                continue;
            }

            // Case 1: brother is RED
            if (brother->color == RED) {
                brother->color = BLACK;
                parent->color = RED;

                leftRotate(parent);

                brother = parent->right;
            }

            // Case 2: both brother's children are BLACK
            bool leftBlack =
                brother->left == nullptr ||
                brother->left->color == BLACK;

            bool rightBlack =
                brother->right == nullptr ||
                brother->right->color == BLACK;

            if (leftBlack && rightBlack) {
                brother->color = RED;

                node = parent;
                parent = node->parent;
            }
            else {
                // Case 3: brother's right child is BLACK
                if (brother->right == nullptr ||
                    brother->right->color == BLACK) {

                    if (brother->left != nullptr) {
                        brother->left->color = BLACK;
                    }

                    brother->color = RED;

                    rightRotate(brother);

                    brother = parent->right;
                }

                // Case 4
                brother->color = parent->color;
                parent->color = BLACK;

                if (brother->right != nullptr) {
                    brother->right->color = BLACK;
                }

                leftRotate(parent);

                node = root;
                parent = nullptr;
            }
        }

        // node is the right child
        else {
            Node* brother = parent->left;

            if (brother == nullptr) {
                node = parent;
                parent = node->parent;
                continue;
            }

            // Case 1: brother is RED
            if (brother->color == RED) {
                brother->color = BLACK;
                parent->color = RED;

                rightRotate(parent);

                brother = parent->left;
            }

            // Case 2: both brother's children are BLACK
            bool leftBlack =
                brother->left == nullptr ||
                brother->left->color == BLACK;

            bool rightBlack =
                brother->right == nullptr ||
                brother->right->color == BLACK;

            if (leftBlack && rightBlack) {
                brother->color = RED;

                node = parent;
                parent = node->parent;
            }
            else {
                // Case 3: brother's left child is BLACK
                if (brother->left == nullptr ||
                    brother->left->color == BLACK) {

                    if (brother->right != nullptr) {
                        brother->right->color = BLACK;
                    }

                    brother->color = RED;

                    leftRotate(brother);

                    brother = parent->left;
                }

                // Case 4
                brother->color = parent->color;
                parent->color = BLACK;

                if (brother->left != nullptr) {
                    brother->left->color = BLACK;
                }

                rightRotate(parent);

                node = root;
                parent = nullptr;
            }
        }
    }

    if (node != nullptr) {
        node->color = BLACK;
    }
}

RedBlackTree::Node* RedBlackTree::search(Node* node, int key) const {
    while (node != nullptr) {
        if (key == node->key) {
            return node;
        }

        if (key < node->key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    return nullptr;
}

RedBlackTree::Node* RedBlackTree::minimum(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

void RedBlackTree::transplant(Node* oldNode, Node* newNode) {
    if (oldNode->parent == nullptr) {
        root = newNode;
    }
    else if (oldNode == oldNode->parent->left) {
        oldNode->parent->left = newNode;
    }
    else {
        oldNode->parent->right = newNode;
    }

    if (newNode != nullptr) {
        newNode->parent = oldNode->parent;
    }
}

void RedBlackTree::remove(int key) {
    // std::cout << "Remove the element: " << key << std::endl;

    Node* nodeToDelete = search(root, key);

    if (nodeToDelete == nullptr) {
        std::cout << "Element not found" << std::endl;
        return;
    }

    Node* replacement = nodeToDelete;
    Color removedColor = replacement->color;

    Node* child = nullptr;
    Node* childParent = nullptr;

    // Case 1: no left child
    if (nodeToDelete->left == nullptr) {
        child = nodeToDelete->right;
        childParent = nodeToDelete->parent;

        transplant(nodeToDelete, nodeToDelete->right);
    }

    // Case 2: no right child
    else if (nodeToDelete->right == nullptr) {
        child = nodeToDelete->left;
        childParent = nodeToDelete->parent;

        transplant(nodeToDelete, nodeToDelete->left);
    }

    // Case 3: two children
    else {
        replacement = minimum(nodeToDelete->right);

        removedColor = replacement->color;
        child = replacement->right;

        if (replacement->parent == nodeToDelete) {
            childParent = replacement;

            if (child != nullptr) {
                child->parent = replacement;
            }
        }
        else {
            childParent = replacement->parent;

            transplant(replacement, replacement->right);

            replacement->right = nodeToDelete->right;
            replacement->right->parent = replacement;
        }

        transplant(nodeToDelete, replacement);

        replacement->left = nodeToDelete->left;
        replacement->left->parent = replacement;

        replacement->color = nodeToDelete->color;
    }

    delete nodeToDelete;

    // Removing a black node may violate RB properties
    if (removedColor == BLACK) {
        fixRulesAfterRemoval(child, childParent);
    }
}

bool RedBlackTree::contains(int key) const {
    return search(root, key) != nullptr;
}
