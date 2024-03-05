#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_KEYS = 4; 

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool leaf = false) : isLeaf(leaf) {}

    int findKey(int k) {
        return distance(keys.begin(), lower_bound(keys.begin(), keys.end(), k));
    }

    void insertNonFull(int k) {
        int i = keys.size() - 1;

        if (isLeaf) {
            keys.push_back(0);
            while (i >= 0 && k < keys[i]) {
                keys[i + 1] = keys[i];
                --i;
            }
            keys[i + 1] = k;
        } else {
            while (i >= 0 && k < keys[i]) {
                --i;
            }

            if (children[i + 1]->keys.size() == MAX_KEYS * 2 - 1) {
                splitChild(i + 1, children[i + 1]);

                if (k > keys[i + 1]) {
                    ++i;
                }
            }

            children[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->isLeaf);
        keys.insert(keys.begin() + i, y->keys[MAX_KEYS - 1]);

        z->keys.assign(y->keys.begin() + MAX_KEYS, y->keys.end());
        y->keys.erase(y->keys.begin() + MAX_KEYS - 1, y->keys.end());

        if (!y->isLeaf) {
            z->children.assign(y->children.begin() + MAX_KEYS, y->children.end());
            y->children.erase(y->children.begin() + MAX_KEYS, y->children.end());
        }

        children.insert(children.begin() + i + 1, z);
    }
};

class BTree {
private:
    BTreeNode* root;

public:
    BTree() : root(nullptr) {}

    void insert(int k) {
        if (!root) {
            root = new BTreeNode(true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == MAX_KEYS * 2 - 1) {
                BTreeNode* s = new BTreeNode(false);
                s->children.push_back(root);
                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k) {
                    ++i;
                }

                s->children[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

int main() {
    BTree bTree;


    for (int key : {3, 1, 5, 2, 4, 7, 6, 8}) {
        bTree.insert(key);
    }

    

    return 0;
}
