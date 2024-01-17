#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ORDER = 3; // Order of the B+ tree

// Node of the B+ tree
class BPlusTreeNode
{
public:
    vector<int> keys;
    vector<BPlusTreeNode *> children;
    bool isLeaf;

    BPlusTreeNode(bool leaf = false) : isLeaf(leaf) {}

    // Function to find the index of the first key greater than or equal to the given key
    int findKeyIndex(int key) const
    {
        auto it = lower_bound(keys.begin(), keys.end(), key);
        return distance(keys.begin(), it);
    }
};

// B+ tree
class BPlusTree
{
private:
    BPlusTreeNode *root;

    // Function to split a child node
    void splitChild(BPlusTreeNode *parent, int childIndex)
    {
        BPlusTreeNode *child = parent->children[childIndex];
        BPlusTreeNode *newChild = new BPlusTreeNode(child->isLeaf);

        // Move half of the keys and children to the new child
        newChild->keys.assign(child->keys.begin() + ORDER / 2, child->keys.end());
        child->keys.erase(child->keys.begin() + ORDER / 2, child->keys.end());

        if (!child->isLeaf)
        {
            newChild->children.assign(child->children.begin() + ORDER / 2, child->children.end());
            child->children.erase(child->children.begin() + ORDER / 2, child->children.end());
        }

        // Insert the middle key and the new child into the parent
        parent->keys.insert(parent->keys.begin() + childIndex, newChild->keys.front());
        parent->children.insert(parent->children.begin() + childIndex + 1, newChild);

        // Update the parent's key if necessary
        child->keys.pop_back();
    }

    // Function to insert a key into a non-full node
    void insertNonFull(BPlusTreeNode *node, int key)
    {
        int index = node->findKeyIndex(key);

        if (node->isLeaf)
        {
            node->keys.insert(node->keys.begin() + index, key);
        }
        else
        {
            BPlusTreeNode *child = node->children[index];
            if (child->keys.size() == ORDER - 1)
            {
                splitChild(node, index);
                if (key > node->keys[index])
                {
                    index++;
                }
            }
            insertNonFull(node->children[index], key);
        }
    }

    // Function to search for a key in the B+ tree
    bool searchKey(BPlusTreeNode *node, int key) const
    {
        if (node == nullptr)
        {
            return false;
        }

        int index = node->findKeyIndex(key);

        if (index < node->keys.size() && key == node->keys[index])
        {
            return true; // Key found
        }
        else if (node->isLeaf)
        {
            return false; // Key not found in a leaf node
        }
        else
        {
            return searchKey(node->children[index], key); // Recur to the appropriate child
        }
    }

public:
    BPlusTree() : root(nullptr) {}

    // Function to insert a key into the B+ tree
    void insert(int key)
    {
        if (root == nullptr)
        {
            root = new BPlusTreeNode(true);
            root->keys.push_back(key);
        }
        else if (root->keys.size() == ORDER - 1)
        {
            BPlusTreeNode *newRoot = new BPlusTreeNode(false);
            newRoot->children.push_back(root);
            root = newRoot;
            splitChild(newRoot, 0);
            insertNonFull(newRoot, key);
        }
        else
        {
            insertNonFull(root, key);
        }
    }

    // Function to search for a key in the B+ tree
    bool search(int key) const
    {
        return (root == nullptr) ? false : searchKey(root, key);
    }
};

int main()
{
    BPlusTree bPlusTree;

    // Insert some keys
    bPlusTree.insert(10);
    bPlusTree.insert(20);
    bPlusTree.insert(5);
    bPlusTree.insert(6);
    bPlusTree.insert(12);

    // Search for keys
    cout << "Search for 5: " << (bPlusTree.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search for 15: " << (bPlusTree.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
