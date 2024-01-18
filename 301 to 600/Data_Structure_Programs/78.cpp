#include <iostream>
#include <vector>
using namespace std;

enum Color { RED, BLACK };

class Node {
public:
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int k, Color c = RED, Node* l = nullptr, Node* r = nullptr, Node* p = nullptr)
        : key(k), color(c), left(l), right(r), parent(p) {}
};

class PersistentRedBlackTree {
private:
  vector<Node*> versions; 

    Node* insertHelper(Node* root, int key) {
        if (!root) {
            return new Node(key, RED);
        }

        if (key < root->key) {
            root->left = insertHelper(root->left, key);
            root->left->parent = root;
        } else if (key > root->key) {
            root->right = insertHelper(root->right, key);
            root->right->parent = root;
        }

        return balance(root);
    }

  
    Node* balance(Node* node) {
        if (node->right && node->right->color == RED) {
            node = rotateLeft(node);
        }

        if (node->left && node->left->color == RED && node->left->left && node->left->left->color == RED) {
            node = rotateRight(node);
        }

        if (node->left && node->left->color == RED && node->right && node->right->color == RED) {
            flipColors(node);
        }

        return node;
    }

    
    Node* rotateLeft(Node* h) {
        Node* x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    
    Node* rotateRight(Node* h) {
        Node* x = h->left;
        h->left = x->right; 
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    
    void flipColors(Node* h) {
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

public:
    PersistentRedBlackTree() {
        versions.push_back(nullptr); 
    }

    
    void insert(int key) {
        Node* root = insertHelper(versions.back(), key);
        root->color = BLACK; 
        versions.push_back(root);
    }

    
    void queryLatest() {
      cout << "Latest version: ";
        printTree(versions.back());
      cout << "\n";
    }

    
    void printTree(Node* root) {
        if (root) {
            printTree(root->left);
          cout << root->key << " ";
            printTree(root->right);
        }
    }
};

int main() {
    PersistentRedBlackTree prbTree;

    
    prbTree.insert(5);
    prbTree.insert(3);
    prbTree.insert(7);
    prbTree.queryLatest(); 

    
    prbTree.insert(2);
    prbTree.insert(6);
    prbTree.queryLatest(); 

    return 0;
}
