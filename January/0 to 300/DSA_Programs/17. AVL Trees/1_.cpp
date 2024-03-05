#include <iostream>
using namespace std;

class AVLNode
{
public:
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(AVLNode *node)
{
    return (node == nullptr) ? 0 : node->height;
}

int getBalanceFactor(AVLNode *node)
{
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

void updateHeight(AVLNode *node)
{
    if (node != nullptr)
    {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode *balance(AVLNode *root)
{
    updateHeight(root);

    int balance = getBalanceFactor(root);

    // (LL)
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // (LR)
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // (RR)
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // (RL)
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

AVLNode *insert(AVLNode *root, int value)
{
    if (root == nullptr)
    {
        return new AVLNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        return root;
    }

    updateHeight(root);

    return balance(root);
}

AVLNode *minValueNode(AVLNode *node)
{
    AVLNode *current = node;

    while (current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}

AVLNode *deleteNode(AVLNode *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            AVLNode *temp = (root->left != nullptr) ? root->left : root->right;

            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
            {
                *root = *temp;
            }

            delete temp;
        }
        else
        {
            AVLNode *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
    {
        return root;
    }

    updateHeight(root);

    return balance(root);
}

bool search(AVLNode *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == value)
    {
        return true;
    }
    else if (value < root->data)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
}

void inorderTraversal(AVLNode *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    AVLNode *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal after insertion: ";
    inorderTraversal(root);
    cout << endl;

    int searchValue = 30;
    cout << "Search for " << searchValue << ": ";
    cout << (search(root, searchValue) ? "Found" : "Not Found") << endl;

    int deleteValue = 30;
    root = deleteNode(root, deleteValue);
    cout << "Inorder traversal after deletion of " << deleteValue << ": ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
