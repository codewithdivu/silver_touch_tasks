#include <iostream>
#include <vector>

class LinkCutTree {
private:
    struct Node {
        int value;
        int sum;
        Node* parent;
        Node* left;
        Node* right;
        bool isRoot;

        Node(int val) : value(val), sum(val), parent(nullptr), left(nullptr), right(nullptr), isRoot(true) {}
    };

    static void update(Node* node) {
        node->sum = node->value;
        if (node->left) node->sum += node->left->sum;
        if (node->right) node->sum += node->right->sum;
    }

    static void rotate(Node* child, Node* parent) {
        Node* grandparent = parent->parent;
        if (!grandparent->isRoot) {
            if (grandparent->left == parent) grandparent->left = child;
            else grandparent->right = child;
        }

        if (parent->left == child) {
            parent->left = child->right;
            child->right = parent;
        } else {
            parent->right = child->left;
            child->left = parent;
        }

        update(parent);
        update(child);
        child->parent = grandparent;
        parent->parent = child;
    }

    static void splay(Node* node) {
        while (!node->isRoot) {
            Node* parent = node->parent;
            Node* grandparent = parent->parent;

            if (!parent->isRoot) {
                if ((grandparent->left == parent) == (parent->left == node)) {
                    rotate(parent, grandparent);
                } else {
                    rotate(node, parent);
                }
            }

            rotate(node, grandparent);
        }
    }

public:
  
};

int main() {
    
    return 0;
}
