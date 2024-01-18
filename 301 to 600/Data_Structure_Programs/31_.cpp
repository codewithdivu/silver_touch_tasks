#include <iostream>
#include <vector>

using namespace std;


struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class PersistentSegmentTree
{
private:
    vector<Node *> roots; 
    int size;             

    
    Node *buildTree(const vector<int> &input, int left, int right)
    {
        if (left == right)
        {
            return new Node(input[left]);
        }

        int mid = (left + right) / 2;

        Node *newNode = new Node(0);
        newNode->left = buildTree(input, left, mid);
        newNode->right = buildTree(input, mid + 1, right);

        
        newNode->value = newNode->left->value + newNode->right->value;

        return newNode;
    }

    
    Node *updateTree(Node *prevNode, int left, int right, int index, int value)
    {
        if (left == right)
        {
            
            return new Node(value);
        }

        int mid = (left + right) / 2;

        Node *newNode = new Node(0);
        if (index <= mid)
        {
            newNode->left = updateTree(prevNode->left, left, mid, index, value);
            newNode->right = prevNode->right;
        }
        else
        {
            newNode->left = prevNode->left;
            newNode->right = updateTree(prevNode->right, mid + 1, right, index, value);
        }

        
        newNode->value = newNode->left->value + newNode->right->value;

        return newNode;
    }

    
    int queryTree(Node *node, int left, int right, int queryLeft, int queryRight)
    {
        if (node == nullptr || queryLeft > right || queryRight < left)
        {
            return 0;
        }

        if (queryLeft <= left && queryRight >= right)
        {
            return node->value;
        }

        int mid = (left + right) / 2;

        int leftSum = queryTree(node->left, left, mid, queryLeft, queryRight);
        int rightSum = queryTree(node->right, mid + 1, right, queryLeft, queryRight);

        return leftSum + rightSum;
    }

public:
    
    PersistentSegmentTree(const vector<int> &input) : size(input.size())
    {
        roots.push_back(buildTree(input, 0, size - 1));
    }

    
    void update(int version, int index, int value)
    {
        if (version >= roots.size())
        {
            cout << "Error: Version does not exist." << endl;
            return;
        }

        roots.push_back(updateTree(roots[version], 0, size - 1, index, value));
    }

    
    int query(int version, int queryLeft, int queryRight)
    {
        if (version >= roots.size())
        {
            cout << "Error: Version does not exist." << endl;
            return -1;
        }

        return queryTree(roots[version], 0, size - 1, queryLeft, queryRight);
    }
};

int main()
{
    vector<int> initialArray = {1, 2, 3, 4, 5};

    
    PersistentSegmentTree pst(initialArray);

    
    cout << "Initial version: ";
    cout << pst.query(0, 0, 2) << " " << pst.query(0, 1, 4) << endl;

    
    pst.update(0, 2, 10);

    
    cout << "Updated version: ";
    cout << pst.query(1, 0, 2) << " " << pst.query(1, 1, 4) << endl;

    return 0;
}
