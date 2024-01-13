#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool identical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }

    bool left = identical(root1->left, root2->left);
    bool right = identical(root1->right, root2->right);
    bool compare = root1->data == root2->data;

    if (left && right && compare)
    {
        return true;
    }
    return false;
}

int main()
{
    node *root1 = new node(1);

    root1->left = new node(2);
    root1->right = new node(3);

    root1->left->left = new node(4);
    root1->left->right = new node(5);

    root1->left->left->left = new node(7);
    root1->left->left->right = new node(8);

    root1->right->left = new node(6);
    root1->right->right = new node(7);

    node *root2 = new node(1);

    root2->left = new node(2);
    root2->right = new node(3);

    root2->left->left = new node(4);
    root2->left->right = new node(5);

    root2->left->left->left = new node(7);
    root2->left->left->right = new node(8);

    root2->right->left = new node(6);
    root2->right->right = new node(7);

    if (identical(root1, root2))
    {
        cout << "both trees are identical" << endl;
    }
    else
    {
        cout << "trees are not identical" << endl;
    }

    return 0;
}

/*
      1
    /   \
   2     3
  / \   / \
 4   5  6  7
*/