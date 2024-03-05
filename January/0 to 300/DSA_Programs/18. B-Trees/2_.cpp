#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ORDER = 3; 


class BPlusTreeNode
{
public:
    vector<int> keys;
    vector<BPlusTreeNode *> children;
    bool isLeaf;

    BPlusTreeNode(bool leaf = false) : isLeaf(leaf) {}

    
    int findKeyIndex(int key) const
    {
        auto it = lower_bound(keys.begin(), keys.end(), key);
        return distance(keys.begin(), it);
    }
};


class BPlusTree
{
private:
    BPlusTreeNode *root;

    
    void splitChild(BPlusTreeNode *parent, int childIndex)
    {
        BPlusTreeNode *child = parent->children[childIndex];
        BPlusTreeNode *newChild = new BPlusTreeNode(child->isLeaf);

        
        newChild->keys.assign(child->keys.begin() + ORDER / 2, child->keys.end());
        child->keys.erase(child->keys.begin() + ORDER / 2, child->keys.end());

        if (!child->isLeaf)
        {
            newChild->children.assign(child->children.begin() + ORDER / 2, child->children.end());
            child->children.erase(child->children.begin() + ORDER / 2, child->children.end());
        }

        
        parent->keys.insert(parent->keys.begin() + childIndex, newChild->keys.front());
        parent->children.insert(parent->children.begin() + childIndex + 1, newChild);

        
        child->keys.pop_back();
    }

    
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

    
    bool searchKey(BPlusTreeNode *node, int key) const
    {
        if (node == nullptr)
        {
            return false;
        }

        int index = node->findKeyIndex(key);

        if (index < node->keys.size() && key == node->keys[index])
        {
            return true; 
        }
        else if (node->isLeaf)
        {
            return false; 
        }
        else
        {
            return searchKey(node->children[index], key); 
        }
    }

public:
    BPlusTree() : root(nullptr) {}

    
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

    
    bool search(int key) const
    {
        return (root == nullptr) ? false : searchKey(root, key);
    }
};

int main()
{
    BPlusTree bPlusTree;

    
    bPlusTree.insert(10);
    bPlusTree.insert(20);
    bPlusTree.insert(5);
    bPlusTree.insert(6);
    bPlusTree.insert(12);

    
    cout << "Search for 5: " << (bPlusTree.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search for 15: " << (bPlusTree.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
