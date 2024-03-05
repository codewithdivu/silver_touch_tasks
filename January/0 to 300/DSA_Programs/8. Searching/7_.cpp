#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }

    if (root->data > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cin >> data;
    }
}

void breadthFirstSearch(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
        {
            q.push(current->left);
        }

        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    cout << "Enter the data to create BST " << endl;

    takeInput(root);

    return 0;
}
