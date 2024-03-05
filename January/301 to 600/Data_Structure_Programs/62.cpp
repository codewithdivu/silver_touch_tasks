#include <iostream>
#include <string>

using namespace std;

class TernarySearchTree {
private:
    struct Node {
        char data;
        bool isEndOfWord;
        Node* left;
        Node* middle;
        Node* right;

        Node(char ch) : data(ch), isEndOfWord(false), left(nullptr), middle(nullptr), right(nullptr) {}
    };

    Node* root;

    
    Node* insert(Node* node, const string& word, int index) {
        char currentChar = word[index];

        if (node == nullptr) {
            node = new Node(currentChar);
        }

        if (currentChar < node->data) {
            node->left = insert(node->left, word, index);
        } else if (currentChar > node->data) {
            node->right = insert(node->right, word, index);
        } else {
            if (index < word.length() - 1) {
                node->middle = insert(node->middle, word, index + 1);
            } else {
                node->isEndOfWord = true;
            }
        }

        return node;
    }

    
    bool search(Node* node, const string& word, int index) {
        if (node == nullptr) {
            return false;
        }

        char currentChar = word[index];

        if (currentChar < node->data) {
            return search(node->left, word, index);
        } else if (currentChar > node->data) {
            return search(node->right, word, index);
        } else {
            if (index == word.length() - 1) {
                return node->isEndOfWord;
            } else {
                return search(node->middle, word, index + 1);
            }
        }
    }

public:
    TernarySearchTree() : root(nullptr) {}

    
    void insert(const string& word) {
        root = insert(root, word, 0);
    }

    
    bool search(const string& word) {
        return search(root, word, 0);
    }
};

int main() {
    TernarySearchTree tst;

    
    tst.insert("apple");
    tst.insert("banana");
    tst.insert("orange");

    
    cout << "Search for 'apple': " << (tst.search("apple") ? "Found" : "Not found") << endl;
    cout << "Search for 'grape': " << (tst.search("grape") ? "Found" : "Not found") << endl;

    return 0;
}
