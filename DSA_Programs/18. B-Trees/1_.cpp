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

    void splitChild(BTreeNode *parent, int index)
    {
        BTreeNode *child = parent->children[index];
        BTreeNode *newChild = new BTreeNode();

        parent->keys.insert(parent->keys.begin() + index, child->keys[1]);
        parent->children.insert(parent->children.begin() + index + 1, newChild);

        newChild->keys.push_back(child->keys[2]);
        child->keys.erase(child->keys.begin() + 1, child->keys.end());

        if (!child->isLeaf())
        {
            newChild->children.push_back(child->children[2]);
            child->children.erase(child->children.begin() + 2, child->children.end());
        }
    }

    void insertNonFull(BTreeNode *node, int key)
    {
        int i = node->keys.size() - 1;

        if (node->isLeaf())
        {
            while (i >= 0 && key < node->keys[i])
            {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        }
        else
        {
            while (i >= 0 && key < node->keys[i])
            {
                i--;
            }
            i++;

            if (node->children[i]->keys.size() == 3)
            {
                splitChild(node, i);

                if (key > node->keys[i])
                {
                    i++;
                }
            }

            insertNonFull(node->children[i], key);
        }
    }

    bool searchKey(BTreeNode *node, int key) const
    {
        int i = 0;
        while (i < node->keys.size() && key > node->keys[i])
        {
            i++;
        }

        if (i < node->keys.size() && key == node->keys[i])
        {
            return true;
        }
        else if (node->isLeaf())
        {
            return false;
        }
        else
        {
            return searchKey(node->children[i], key);
        }
    }

public:
    BTree() : root(nullptr) {}

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
