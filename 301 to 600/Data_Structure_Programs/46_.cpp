#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node *constructCartesianTree(const vector<int> &sequence)
{
    stack<Node *> stk;

    for (int i = 0; i < sequence.size(); ++i)
    {
        Node *newNode = new Node(sequence[i]);

        while (!stk.empty() && stk.top()->key > sequence[i])
        {
            newNode->left = stk.top();
            stk.pop();
        }

        if (!stk.empty())
        {
            stk.top()->right = newNode;
        }

        stk.push(newNode);
    }

    while (stk.size() > 1)
    {
        stk.pop();
    }

    return stk.top();
}

void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main()
{

    vector<int> sequence = {3, 2, 6, 1, 9};

    Node *root = constructCartesianTree(sequence);

    cout << "Inorder Traversal of Cartesian Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
