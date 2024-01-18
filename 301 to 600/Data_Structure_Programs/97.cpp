#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int index;
    Node* left;
    Node* right;

    Node(int key, int index) : key(key), index(index), left(nullptr), right(nullptr) {}
};

class CartesianTree {
private:
    vector<Node*> roots; 

    Node* buildTree(const vector<int>& arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int minIndex = findMinIndex(arr, start, end);
        Node* root = new Node(arr[minIndex], minIndex);

        root->left = buildTree(arr, start, minIndex - 1);
        root->right = buildTree(arr, minIndex + 1, end);

        return root;
    }

    int findMinIndex(const vector<int>& arr, int start, int end) {
        int minIndex = start;
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }

public:
    CartesianTree(const vector<int>& arr) {
        roots.push_back(buildTree(arr, 0, arr.size() - 1));
    }

   
    int query(int version, int left, int right) const {
        return queryHelper(roots[version], left, right);
    }

    int queryHelper(Node* root, int left, int right) const {
        if (!root || left > right) {
            return INT_MAX;
        }

        int rootIndex = root->index;

        if (rootIndex >= left && rootIndex <= right) {
            return root->key;
        } else if (rootIndex > right) {
            return min(root->key, queryHelper(root->left, left, right));
        } else {
            return min(root->key, queryHelper(root->right, left, right));
        }
    }

    
    void update(int version, int index, int newValue) {
        Node* newRoot = updateHelper(roots[version], index, newValue);
        roots.push_back(newRoot);
    }

    Node* updateHelper(Node* root, int index, int newValue) {
        if (!root) {
            return nullptr;
        }

        if (root->index == index) {
            root->key = newValue;
        } else if (root->index > index) {
            root->left = updateHelper(root->left, index, newValue);
        } else {
            root->right = updateHelper(root->right, index, newValue);
        }

        return root;
    }
};

int main() {
    vector<int> arr = {4, 2, 7, 1, 5};

    CartesianTree ct(arr);

    cout << "Initial Query: " << ct.query(0, 1, 3) << endl;

    ct.update(0, 2, 3);

    cout << "Updated Query: " << ct.query(1, 1, 3) << endl;

    return 0;
}
