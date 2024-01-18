#include <iostream>
using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int key;
    Color color;
    Node *parent;
    Node *left;
    Node *right;

    Node(int k, Color c) : key(k), color(c), parent(nullptr), left(nullptr), right(nullptr) {}
};

class RedBlackTree
{
private:
    Node *root;
    Node *nil;

    void leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;

        if (y->left != nil)
        {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nil)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node *y)
    {
        Node *x = y->left;
        y->left = x->right;

        if (x->right != nil)
        {
            x->right->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nil)
        {
            root = x;
        }
        else if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

    void insertFixup(Node *z)
    {
        while (z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node *y = z->parent->parent->right;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                Node *y = z->parent->parent->left;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node *u, Node *v)
    {
        if (u->parent == nil)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteNode(Node *z)
    {
        Node *y = z;
        Node *x;
        Color yOriginalColor = y->color;

        if (z->left == nil)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == nil)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        if (yOriginalColor == BLACK)
        {
            deleteFixup(x);
        }
        delete z;
    }

    void deleteFixup(Node *x)
    {
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                Node *w = x->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }

                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (w->right->color == BLACK)
                    {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                Node *w = x->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }

                if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (w->left->color == BLACK)
                    {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    Node *minimum(Node *x)
    {
        while (x->left != nil)
        {
            x = x->left;
        }
        return x;
    }

    void inorderTraversal(Node *x)
    {
        if (x != nil)
        {
            inorderTraversal(x->left);
            cout << "(" << x->key << ", " << (x->color == RED ? "RED" : "BLACK") << ") ";
            inorderTraversal(x->right);
        }
    }

public:
    RedBlackTree()
    {
        nil = new Node(0, BLACK);
        root = nil;
    }

    void insert(int key)
    {
        Node *z = new Node(key, RED);
        Node *y = nil;
        Node *x = root;

        while (x != nil)
        {
            y = x;
            if (z->key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == nil)
        {
            root = z;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }

        z->left = nil;
        z->right = nil;
        z->color = RED;

        insertFixup(z);
    }

    void remove(int key)
    {
        Node *z = search(root, key);

        if (z != nil)
        {
            deleteNode(z);
        }
    }

    Node *search(Node *x, int key)
    {
        while (x != nil && key != x->key)
        {
            if (key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        return x;
    }

    void print()
    {
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{

    RedBlackTree rbTree;

    rbTree.insert(10);
    rbTree.insert(20);
    rbTree.insert(15);
    rbTree.insert(25);
    rbTree.insert(5);

    cout << "Inorder traversal of the Red-Black Tree: ";
    rbTree.print();

    rbTree.remove(15);

    cout << "Inorder traversal after removing key 15: ";
    rbTree.print();

    return 0;
}
