#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class LinkCutTree
{
public:
    struct Node
    {
        int key;
        Node *parent, *left, *right;
        bool isRoot, isReversed;

        Node(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr), isRoot(true), isReversed(false) {}
    };

    vector<Node *> nodes;

    void makeRoot(Node *u)
    {
        access(u);
        splay(u);
        u->isReversed = !u->isReversed;
    }

    void link(Node *u, Node *v)
    {
        makeRoot(u);
        u->parent = v;
    }

    void cut(Node *u, Node *v)
    {
        makeRoot(u);
        access(v);
        splay(v);

        if (v->left == u)
        {
            u->parent = nullptr;
            v->left = nullptr;
        }
    }

    Node *access(Node *u)
    {
        Node *v = nullptr;
        for (Node *x = u; x != nullptr; x = x->parent)
        {
            splay(x);
            x->right = v;
            v = x;
        }
        splay(u);
        return v;
    }

    Node *findRoot(Node *u)
    {
        access(u);
        while (u->left != nullptr)
        {
            u = u->left;
        }
        splay(u);
        return u;
    }

    void makeRoot(int u)
    {
        makeRoot(nodes[u]);
    }

    void link(int u, int v)
    {
        link(nodes[u], nodes[v]);
    }

    void cut(int u, int v)
    {
        cut(nodes[u], nodes[v]);
    }

    bool isConnected(int u, int v)
    {
        return findRoot(nodes[u]) == findRoot(nodes[v]);
    }

    void splay(Node *x)
    {
        while (!x->isRoot)
        {
            Node *p = x->parent;
            if (!p->isRoot)
            {
                Node *g = p->parent;
                if ((x == p->left) == (p == g->left))
                    rotate(p);
                else
                    rotate(x);
            }
            rotate(x);
        }
    }

    void rotate(Node *x)
    {
        Node *p = x->parent;
        if (x == p->left)
        {
            p->left = x->right;
            if (x->right != nullptr)
                x->right->parent = p;
            x->right = p;
        }
        else
        {
            p->right = x->left;
            if (x->left != nullptr)
                x->left->parent = p;
            x->left = p;
        }

        x->parent = p->parent;
        p->parent = x;

        if (x->parent != nullptr)
        {
            if (p == x->parent->left)
                x->parent->left = x;
            else
                x->parent->right = x;
        }
        else
        {
            x->isRoot = true;
        }
    }

public:
    LinkCutTree(int n)
    {
        nodes.resize(n);
        for (int i = 0; i < n; ++i)
        {
            nodes[i] = new Node(i);
        }
    }
};

int main()
{

    int n = 5;
    LinkCutTree lct(n);

    lct.link(0, 1);
    lct.link(1, 2);
    lct.link(2, 3);
    lct.link(3, 4);

    cout << "Is 0 connected to 4? " << (lct.isConnected(0, 4) ? "Yes" : "No") << endl;

    lct.cut(2, 3);

    cout << "Is 2 connected to 3? " << (lct.isConnected(2, 3) ? "Yes" : "No") << endl;

    lct.link(0, 4);

    cout << "Is 1 connected to 4? " << (lct.isConnected(1, 4) ? "Yes" : "No") << endl;

    return 0;
}
