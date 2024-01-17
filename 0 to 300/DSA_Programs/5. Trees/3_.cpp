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

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

bool isBalanced(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int left = isBalanced(root->left);
    int right = isBalanced(root->right);
    int compare = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && compare)
    {
        return true;
    }
    return false;
}

int main()
{
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    // root->left->left->left = new node(50);
    // root->left->left->right = new node(50);

    root->right->left = new node(6);
    root->right->right = new node(7);

    if (isBalanced(root))
    {
        cout << "Binary tree is balanced" << endl;
    }
    else
    {
        cout << "Binary tree is not-balanced" << endl;
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