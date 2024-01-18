#include <iostream>
#include <cstdlib>

using namespace std;

struct TreapNode
{
    int key;
    int priority;
    TreapNode *left;
    TreapNode *right;

    TreapNode(int k, int p) : key(k), priority(p), left(nullptr), right(nullptr) {}
};

class Treap
{
private:
    TreapNode *root;

    TreapNode *rotateRight(TreapNode *y)
    {
        TreapNode *x = y->left;
        TreapNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }

    TreapNode *rotateLeft(TreapNode *x)
    {
        TreapNode *y = x->right;
        TreapNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    TreapNode *insertHelper(TreapNode *root, int key, int priority)
    {
        if (root == nullptr)
        {
            return new TreapNode(key, priority);
        }

        if (key <= root->key)
        {

            root->left = insertHelper(root->left, key, priority);

            if (root->left->priority > root->priority)
            {
                root = rotateRight(root);
            }
        }
        else
        {

            root->right = insertHelper(root->right, key, priority);

            if (root->right->priority > root->priority)
            {
                root = rotateLeft(root);
            }
        }

        return root;
    }

    void inorderTraversal(TreapNode *root)
    {
        if (root != nullptr)
        {
            inorderTraversal(root->left);
            cout << "(" << root->key << ", " << root->priority << ") ";
            inorderTraversal(root->right);
        }
    }

public:
    Treap() : root(nullptr) {}

    void insert(int key)
    {
        int priority = rand();
        root = insertHelper(root, key, priority);
    }

    void print()
    {
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{

    Treap treap;

    treap.insert(10);
    treap.insert(20);
    treap.insert(5);
    treap.insert(15);
    treap.insert(25);

    cout << "Inorder traversal of the Treap: ";
    treap.print();

    return 0;
}
