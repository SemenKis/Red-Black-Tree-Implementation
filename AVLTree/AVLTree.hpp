#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

class AVLTree {
private:
    struct Node {
        int key;
        int height;

        Node* left;
        Node* right;

        Node(int key)
            : key(key),
              height(1),
              left(nullptr),
              right(nullptr) {
        }
    };

    Node* root;

    int height(Node* node) const;
    int getBalance(Node* node) const;

    Node* leftRotate(Node* node);
    Node* rightRotate(Node* node);

    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);

    Node* minimum(Node* node) const;

    bool search(Node* node, int key) const;

    void printInOrder(Node* node) const;

    void destroy(Node* node);

public:
    AVLTree();
    ~AVLTree();

    bool empty() const;

    void insert(int key);
    void remove(int key);

    bool contains(int key) const;

    void print() const;
};

#endif