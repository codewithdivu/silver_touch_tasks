#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    int value;
    int index;
    Node* left;
    Node* right;

    Node(int val, int idx) : value(val), index(idx), left(nullptr), right(nullptr) {}
};

class CartesianTree {
private:
    Node* root;

    
    Node* buildTree(const vector<int>& arr, const vector<int>& indices, int low, int high) {
        if (low > high) {
            return nullptr;
        }

        int minIndex = low;
        for (int i = low + 1; i <= high; ++i) {
            if (arr[indices[i]] < arr[indices[minIndex]]) {
                minIndex = i;
            }
        }

        Node* node = new Node(arr[indices[minIndex]], indices[minIndex]);
        node->left = buildTree(arr, indices, low, minIndex - 1);
        node->right = buildTree(arr, indices, minIndex + 1, high);

        return node;
    }

    
    int rangeMinQuery(Node* node, int start, int end) {
        if (!node) {
            return numeric_limits<int>::max();
        }

        if (node->index >= start && node->index <= end) {
            return node->value;
        }

        if (node->index > end) {
            return rangeMinQuery(node->left, start, end);
        }

        return min(node->value, rangeMinQuery(node->right, start, end));
    }

public:
    CartesianTree(const vector<int>& arr) {
        int n = arr.size();
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }

        root = buildTree(arr, indices, 0, n - 1);
    }

    
    int rangeMinQuery(int start, int end) {
        return rangeMinQuery(root, start, end);
    }
};

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};
    CartesianTree cartesianTree(arr);

    
    int start = 2;
    int end = 5;
    int result = cartesianTree.rangeMinQuery(start, end);

    cout << "Minimum value in range [" << start << ", " << end << "] is: " << result << endl;

    return 0;
}
