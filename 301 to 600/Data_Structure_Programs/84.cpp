#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, sum, lazy;
    Node *left, *right;

    Node(int v) : val(v), sum(v), lazy(0), left(nullptr), right(nullptr) {}
};

Node* build(int l, int r) {
    if (l > r) return nullptr;
    Node *node = new Node(0);
    if (l == r) return node;
    int m = (l + r) / 2;
    node->left = build(l, m);
    node->right = build(m + 1, r);
    return node;
}

void push(Node* node) {
    if (node == nullptr || node->lazy == 0) return;
    node->val += node->lazy;
    node->sum += (long long)node->lazy * (r - l + 1);
    if (node->left != nullptr) node->left->lazy += node->lazy;
    if (node->right != nullptr) node->right->lazy += node->lazy;
    node->lazy = 0;
}

void update(Node* node, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql) return;
    if (l >= ql && r <= qr) {
        node->val += val;
        node->sum += (long long)val * (r - l + 1);
        node->lazy += val;
        return;
    }
    push(node);
    int m = (l + r) / 2;
    update(node->left, l, m, ql, qr, val);
    update(node->right, m + 1, r, ql, qr, val);
    node->sum = node->left->sum + node->right->sum + node->val;
}

int query(Node* node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return node->sum;
    push(node);
    int m = (l + r) / 2;
    return query(node->left, l, m, ql, qr) + query(node->right, m + 1, r, ql, qr) + node->val;
}

void euler_tour(Node* node, int l, int r, vector<Node*> &tour) {
    if (node == nullptr) return;
    tour.push_back(node);
    if (node->left != nullptr) euler_tour(node->left, l, (l + r) / 2, tour);
    if (node->right != nullptr) euler_tour(node->right, (l + r) / 2 + 1, r, tour);
}

void build_euler_tour(Node* root, Node* &head, Node* &tail) {
    vector<Node*> tour;
    euler_tour(root, 0, 100000, tour);
    head = tour[0];
    tail = tour.back();
    for (int i = 1; i < tour.size(); i++) {
        tour[i]->left = tour[i - 1];
        tour[i - 1]->right = tour[i];
    }
}

void update_euler_tour(Node* node, int val) {
    node->val += val;
    node->sum += (long long)val * 2;
    node->lazy += val;
    if (node->left != nullptr) update_euler_tour(node->left, val);
    if (node->right != nullptr) update_euler_tour(node->right, val);
}

int query_euler_tour(Node* node, int ql, int qr) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return node->sum;
    if (ql <= node->left->r && node->left->r <= qr) return query_euler_tour(node->left, ql, qr);
    if (ql <= node->right->l && node->right->l <= qr) return query_euler_tour(node->right, ql, qr);
    return query(node, node->left->l, node->right->r, ql, qr) + node->val;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* head, *tail;
    build_euler_tour(root, head, tail);

    update_euler_tour(head, 10);
    cout << query_euler_tour(head, 1, 7) << endl; // 110

    update(head->left, 1, 5, 3, 3, 20);
    cout << query(head, 1, 7) << endl; // 150

    return 0;
}