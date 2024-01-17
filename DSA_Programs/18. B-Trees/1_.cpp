#include <iostream>
#include <vector>
using namespace std;

class BTreeNode
{
public:
    vector<int> keys;
    vector<BTreeNode *> children;

    BTreeNode() {}

    bool isLeaf() const
    {
        return children.empty();
    }
};

class BTree
{
private:
    BTreeNode *root;

    // Function to split a child of a node
    void splitChild(BTreeNode *parent, int index)
    {
        BTreeNode *child = parent->children[index];
        BTreeNode *newChild = new BTreeNode();

        // Move the middle key from the child to the parent
        parent->keys.insert(parent->keys.begin() + index, child->keys[1]);
        parent->children.insert(parent->children.begin() + index + 1, newChild);

        // Copy the second half of keys from the child to the new child
        newChild->keys.push_back(child->keys[2]);
        child->keys.erase(child->keys.begin() + 1, child->keys.end());

        // If the child is not a leaf, move the second half of children as well
        if (!child->isLeaf())
        {
            newChild->children.push_back(child->children[2]);
            child->children.erase(child->children.begin() + 2, child->children.end());
        }
    }

    // Function to insert a key into a node
    void insertNonFull(BTreeNode *node, int key)
    {
        int i = node->keys.size() - 1;

        if (node->isLeaf())
        {
            // Insert the key into the leaf node
            node->keys.push_back(0); // Dummy value
            while (i >= 0 && key < node->keys[i])
            {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        }
        else
        {
            // Find the child to insert the key
            while (i >= 0 && key < node->keys[i])
            {
                i--;
            }
            i++;

            // If the child is full, split it
            if (node->children[i]->keys.size() == 3)
            {
                splitChild(node, i);

                // Determine which of the two children to descend to
                if (key > node->keys[i])
                {
                    i++;
                }
            }

            insertNonFull(node->children[i], key);
        }
    }

    // Function to search for a key in the B-tree
    bool searchKey(BTreeNode *node, int key) const
    {
        int i = 0;
        while (i < node->keys.size() && key > node->keys[i])
        {
            i++;
        }

        if (i < node->keys.size() && key == node->keys[i])
        {
            return true; // Key found
        }
        else if (node->isLeaf())
        {
            return false; // Key not found in a leaf node
        }
        else
        {
            return searchKey(node->children[i], key); // Recur to the appropriate child
        }
    }

public:
    BTree() : root(nullptr) {}

    // Function to insert a key into the B-tree
    void insert(int key)
    {
        if (root == nullptr)
        {
            root = new BTreeNode();
            root->keys.push_back(key);
        }
        else if (root->keys.size() == 3)
        {
            BTreeNode *newRoot = new BTreeNode();
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

    // Function to search for a key in the B-tree
    bool search(int key) const
    {
        return (root == nullptr) ? false : searchKey(root, key);
    }
};

int main()
{
    BTree btree;

    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);

    cout << "Search for 5: " << (btree.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search for 15: " << (btree.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
