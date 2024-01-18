#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MIN_DEGREE = 2; 

template <typename Key>
class CacheObliviousBTree {
private:
    struct Node {
        bool isLeaf;
        vector<Key> keys;
        vector<Node*> children;

        Node(bool leaf = true) : isLeaf(leaf) {}
    };

    Node* root;

    void insertNonFull(Node* x, const Key& k) {
        int i = x->keys.size() - 1;
        
        if (x->isLeaf) {
            while (i >= 0 && k < x->keys[i]) {
                --i;
            }

            x->keys.insert(x->keys.begin() + i + 1, k);
        } else {
            while (i >= 0 && k < x->keys[i]) {
                --i;
            }

            ++i; 

            if (x->children[i]->keys.size() == (2 * MIN_DEGREE) - 1) {
                splitChild(x, i);

                if (k > x->keys[i]) {
                    ++i;
                }
            }

            insertNonFull(x->children[i], k);
        }
    }

    void splitChild(Node* x, int i) {
        Node* y = x->children[i];
        Node* z = new Node(y->isLeaf);
        x->children.insert(x->children.begin() + i + 1, z);

        x->keys.insert(x->keys.begin() + i, y->keys[MIN_DEGREE - 1]);

        z->keys = vector<Key>(y->keys.begin() + MIN_DEGREE, y->keys.end());
        y->keys.resize(MIN_DEGREE - 1);

        if (!y->isLeaf) {
            z->children = vector<Node*>(y->children.begin() + MIN_DEGREE, y->children.end());
            y->children.resize(MIN_DEGREE);
        }
    }

public:
    CacheObliviousBTree() : root(nullptr) {}

    void insert(const Key& k) {
        if (!root) {
            root = new Node(true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == (2 * MIN_DEGREE) - 1) {
                Node* newRoot = new Node(false);
                newRoot->children.push_back(root);
                root = newRoot;
                splitChild(root, 0);
            }

            insertNonFull(root, k);
        }
    }

    void display() const {
        display(root, 0);
    }

    void display(Node* x, int depth) const {
        if (x != nullptr) {
            for (int i = 0; i < x->keys.size(); ++i) {
                display(x->children[i], depth + 1);
                cout << "Depth " << depth << ", Key " << x->keys[i] << endl;
            }
            display(x->children.back(), depth + 1);
        }
    }
};

int main() {
    CacheObliviousBTree<int> bTree;

    for (int i = 1; i <= 10; ++i) {
        bTree.insert(i);
    }

    bTree.display();

    return 0;
}
