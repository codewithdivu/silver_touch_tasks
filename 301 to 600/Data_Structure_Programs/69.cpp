#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

class YFastTrieNode {
public:
    int key;
    YFastTrieNode* left;
    YFastTrieNode* right;

    YFastTrieNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class YFastTrie {
public:
    set<int> elements; 
    YFastTrieNode* root;
    vector<set<int>> levelSets;
    int universeSize;

    YFastTrie(int size) : root(nullptr), universeSize(size) {
        int levels = log2(universeSize) + 1;
        levelSets.resize(levels);
    }

    
    void insert(int key) {
        elements.insert(key);
        if (root == nullptr) {
            root = new YFastTrieNode(key);
        } else {
            YFastTrieNode* current = root;
            for (int i = levelSets.size() - 1; i >= 0; --i) {
                if (key < current->key) {
                    if (current->left == nullptr) {
                        current->left = new YFastTrieNode(key);
                        levelSets[i].insert(key);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = new YFastTrieNode(key);
                        levelSets[i].insert(key);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    
    int successor(int key) {
        auto it = elements.upper_bound(key);
        if (it != elements.end()) {
            return *it;
        }
        return -1; 
    }

    
    int predecessor(int key) {
        auto it = elements.lower_bound(key);
        if (it != elements.begin()) {
            --it;
            return *it;
        }
        return -1; 
    }

    
    void remove(int key) {
        if (elements.find(key) == elements.end()) {
            return; 
        }

        elements.erase(key);

        
        
    }
};

int main() {
    
    YFastTrie yFastTrie(100);
    yFastTrie.insert(10);
    yFastTrie.insert(20);
    yFastTrie.insert(5);

    cout << "Successor of 5: " << yFastTrie.successor(5) << endl;
    cout << "Predecessor of 20: " << yFastTrie.predecessor(20) << endl;

    return 0;
}
