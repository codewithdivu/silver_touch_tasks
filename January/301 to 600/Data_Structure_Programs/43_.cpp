#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;

    Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

class SplayTree
{
private:
    Node *root;

    void zig(Node *x)
    {
        Node *parent = x->parent;

        if (parent->left == x)
        {
            parent->left = x->right;
            if (x->right != nullptr)
            {
                x->right->parent = parent;
            }
            x->right = parent;
        }
        else
        {
            parent->right = x->left;
            if (x->left != nullptr)
            {
                x->left->parent = parent;
            }
            x->left = parent;
        }

        x->parent = parent->parent;
        parent->parent = x;

        if (x->parent != nullptr)
        {
            if (x->parent->left == parent)
            {
                x->parent->left = x;
            }
            else
            {
                x->parent->right = x;
            }
        }
        else
        {
            root = x;
        }
    }

    void zigZig(Node *x)
    {
        zig(x->parent);
        zig(x);
    }

    void zigZag(Node *x)
    {
        zig(x);
        zig(x);
    }

    void splay(Node *x)
    {
        while (x->parent != nullptr)
        {
            Node *parent = x->parent;
            Node *grandparent = parent->parent;

            if (grandparent == nullptr)
            {
                zig(x);
            }
            else if ((parent->left == x && grandparent->left == parent) ||
                     (parent->right == x && grandparent->right == parent))
            {
                zigZig(x);
            }
            else
            {
                zigZag(x);
            }
        }
    }

    Node *insertHelper(Node *root, int key)
    {
        if (root == nullptr)
        {
            return new Node(key);
        }

        if (key < root->key)
        {
            root->left = insertHelper(root->left, key);
            root->left->parent = root;
        }
        else if (key > root->key)
        {
            root->right = insertHelper(root->right, key);
            root->right->parent = root;
        }
        else
        {

            return root;
        }

        return root;
    }

public:
    SplayTree() : root(nullptr) {}

    void insert(int key)
    {
        root = insertHelper(root, key);
        splay(root->left);
    }

    bool search(int key)
    {
        Node *current = root;

        while (current != nullptr)
        {
            if (key < current->key)
            {
                current = current->left;
            }
            else if (key > current->key)
            {
                current = current->right;
            }
            else
            {
                splay(current);
                return true;
            }
        }

        return false;
    }

    void inorderTraversal(Node *x)
    {
        if (x != nullptr)
        {
            inorderTraversal(x->left);
            cout << x->key << " ";
            inorderTraversal(x->right);
        }
    }

    void print()
    {
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{

    SplayTree splayTree;

    splayTree.insert(50);
    splayTree.insert(30);
    splayTree.insert(70);
    splayTree.insert(20);
    splayTree.insert(40);

    cout << "Inorder traversal of the Splay Tree: ";
    splayTree.print();

    splayTree.search(40);

    cout << "Inorder traversal after searching for key 40: ";
    splayTree.print();

    return 0;
}
