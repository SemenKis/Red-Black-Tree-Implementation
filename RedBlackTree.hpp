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

public:
    RedBlackTree();

    bool empty() const;
};

#endif