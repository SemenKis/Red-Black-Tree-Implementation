#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

class RedBlackTree {
private:
    enum Color {
        RED,
        BLACK
    };

    struct Node {
        int key;
        Color color;

        Node* left;
        Node* right;
        Node* parent;

        Node(int key)
            : key(key),
              color(RED),
              left(nullptr),
              right(nullptr),
              parent(nullptr) {
        }
    };

    Node* root;

    void printInOrder(Node* node) const;

    void leftRotate(Node* node);
    void rightRotate(Node* node);
    void balance(Node* node);

public:
    RedBlackTree();

    bool empty() const;
    void insert(int key);
    void print() const;
};

#endif