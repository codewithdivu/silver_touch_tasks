#include <iostream>
#include <cmath>

class ScapegoatTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;

        Node(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;
    int maxSize;

    
    Node* rebuildTree(Node* node, int count) {
        Node** nodes = new Node*[count];
        int index = 0;
        storeNodesInArray(node, nodes, index);

        return buildTreeFromArray(nodes, 0, count - 1);
    }

    
    void storeNodesInArray(Node* node, Node** nodes, int& index) {
        if (node == nullptr) {
            return;
        }

        storeNodesInArray(node->left, nodes, index);
        nodes[index++] = node;
        storeNodesInArray(node->right, nodes, index);
    }

    
    Node* buildTreeFromArray(Node** nodes, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        Node* node = nodes[mid];

        node->left = buildTreeFromArray(nodes, start, mid - 1);
        node->right = buildTreeFromArray(nodes, mid + 1, end);

        return node;
    }

    
    bool isUnbalanced(Node* node) {
        int lh = height(node->left);
        int rh = height(node->right);
        return (lh > 2 * rh) || (rh > 2 * lh);
    }

    
    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(height(node->left), height(node->right));
    }

    
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            size++;
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        
        if (isUnbalanced(node)) {
            return rebuildTree(node, size);
        }

        return node;
    }

    
    bool search(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }

        if (key < node->key) {
            return search(node->left, key);
        } else if (key > node->key) {
            return search(node->right, key);
        } else {
            return true; 
        }
    }

public:
    ScapegoatTree(int maxNodes) : root(nullptr), size(0), maxSize(maxNodes) {}

    void insert(int key) {
        root = insert(root, key);

        
        if (size > maxSize) {
            root = rebuildTree(root, size);
            maxSize = size;
        }
    }

    bool search(int key) {
        return search(root, key);
    }

    
    

    
    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left);
        std::cout << node->key << " ";
        inOrderTraversal(node->right);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
    }
};

int main() {
    ScapegoatTree stree(5);

    stree.insert(3);
    stree.insert(1);
    stree.insert(5);
    stree.insert(2);
    stree.insert(4);

    stree.inOrderTraversal(); 

    std::cout << std::endl;

    
    std::cout << "Search for 2: " << (stree.search(2) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 6: " << (stree.search(6) ? "Found" : "Not found") << std::endl;

    return 0;
}
