#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
using namespace std;

class TwoLevelTree {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        vector<int> values;
    };

    TrieNode* root;

public:
    TwoLevelTree() : root(new TrieNode) {}

    void insert(const string& key, int value) {
        TrieNode* current = root;

        for (char c : key) {
            if (!current->children[c]) {
                current->children[c] = new TrieNode;
            }
            current = current->children[c];
        }

        current->values.push_back(value);
    }

    vector<int> search(const string& key) {
        TrieNode* current = root;

        for (char c : key) {
            if (!current->children[c]) {
                return {}; // Key not found
            }
            current = current->children[c];
        }

        return current->values;
    }
};

int main() {
    TwoLevelTree tree;
    tree.insert("apple", 1);
    tree.insert("app", 2);

    auto result = tree.search("app");
    for (int value : result) {
        cout << value << " ";
    }

    return 0;
}
