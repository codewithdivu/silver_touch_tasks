#include <iostream>
#include <cstdlib>  
using namespace std;


struct Node {
    int key;
    int size;  
    Node* left;
    Node* right;

    Node(int k) : key(k), size(1), left(nullptr), right(nullptr) {}
};


class OrderStatisticTree {
private:
    Node* root;

    int getSize(Node* node) {
        return node ? node->size : 0;
    }

    void updateSize(Node* node) {
        if (node) {
            node->size = getSize(node->left) + getSize(node->right) + 1;
        }
    }

    Node* insert(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }

        updateSize(node);
        return node;
    }

    int kthSmallestUtil(Node* node, int k) {
        if (!node) {
            return -1;  
        }

        int leftSize = getSize(node->left);

        if (k == leftSize + 1) {
            return node->key;
        } else if (k <= leftSize) {
            return kthSmallestUtil(node->left, k);
        } else {
            return kthSmallestUtil(node->right, k - leftSize - 1);
        }
    }

public:
    OrderStatisticTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    int kthSmallest(int k) {
        return kthSmallestUtil(root, k);
    }
};

int main() {
    OrderStatisticTree ost;

   
    for (int i = 1; i <= 10; ++i) {
        ost.insert(rand() % 100);
    }

    int k = 3;
    cout << "The " << k << "-th smallest element is: " << ost.kthSmallest(k) << endl;

    return 0;
}
