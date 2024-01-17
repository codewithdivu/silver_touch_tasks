#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int low, high;

    Interval(int l, int h) : low(l), high(h) {}
};

struct Node {
    Interval interval;
    int maxHigh;  // Maximum high value in the subtree rooted at this node
    Node* left;
    Node* right;

    Node(Interval i) : interval(i), maxHigh(i.high), left(nullptr), right(nullptr) {}
};

class IntervalTree {
private:
    Node* root;

public:
    IntervalTree() : root(nullptr) {}

    // Function to insert an interval into the interval tree
    void insert(Interval i) {
        root = insertUtil(root, i);
    }

    // Function to delete an interval from the interval tree
    void deleteInterval(Interval i) {
        root = deleteUtil(root, i);
    }

    // Function to search for intervals that overlap with a given interval
    vector<Interval> search(Interval i) {
        vector<Interval> result;
        searchUtil(root, i, result);
        return result;
    }

private:
    // Utility function to insert an interval into the interval tree
    Node* insertUtil(Node* root, Interval i) {
        if (root == nullptr) {
            return new Node(i);
        }

        // Update the maximum high value in the subtree
        root->maxHigh = max(root->maxHigh, i.high);

        // Recur for the left or right subtree based on the low value
        if (i.low < root->interval.low) {
            root->left = insertUtil(root->left, i);
        } else {
            root->right = insertUtil(root->right, i);
        }

        return root;
    }

    // Utility function to delete an interval from the interval tree
    Node* deleteUtil(Node* root, Interval i) {
        if (root == nullptr) {
            return nullptr;
        }

        // If the interval to be deleted lies to the left of the root interval
        if (i.low < root->interval.low) {
            root->left = deleteUtil(root->left, i);
        }
        // If the interval to be deleted lies to the right of the root interval
        else if (i.low > root->interval.low) {
            root->right = deleteUtil(root->right, i);
        }
        // If the interval to be deleted is the same as the root interval
        else {
            // If the root has only a right child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            // If the root has only a left child
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // If the root has two children, get the inorder successor (smallest
            // in the right subtree) and copy its interval to this node
            Node* successor = findMin(root->right);
            root->interval = successor->interval;

            // Delete the inorder successor
            root->right = deleteUtil(root->right, successor->interval);
        }

        // Update the maximum high value in the subtree
        root->maxHigh = max(getMaxHigh(root->left), getMaxHigh(root->right));

        return root;
    }

    // Utility function to find the node with the minimum low value in a subtree
    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Utility function to get the maximum high value in a subtree
    int getMaxHigh(Node* root) {
        return (root != nullptr) ? root->maxHigh : INT_MIN;
    }

    // Utility function to search for intervals that overlap with a given interval
    void searchUtil(Node* root, Interval i, vector<Interval>& result) {
        if (root == nullptr) {
            return;
        }

        // Check if the current interval overlaps with the given interval
        if (i.low <= root->interval.high && root->interval.low <= i.high) {
            result.push_back(root->interval);
        }

        // If the left subtree has a node with a maximum high value greater than
        // or equal to the low value of the given interval, then search the left subtree
        if (root->left != nullptr && i.low <= root->left->maxHigh) {
            searchUtil(root->left, i, result);
        }

        // Search the right subtree
        searchUtil(root->right, i, result);
    }
};

int main() {
    IntervalTree intervalTree;

    // Insert intervals into the interval tree
    intervalTree.insert(Interval(15, 20));
    intervalTree.insert(Interval(10, 30));
    intervalTree.insert(Interval(5, 20));
    intervalTree.insert(Interval(12, 15));
    intervalTree.insert(Interval(17, 19));
    intervalTree.insert(Interval(30, 40));

    // Search for intervals that overlap with a given interval
    Interval searchInterval(14, 16);
    vector<Interval> overlappingIntervals = intervalTree.search(searchInterval);

    // Output the overlapping intervals
    cout << "Overlapping Intervals with [" << searchInterval.low << ", " << searchInterval.high << "]:" << endl;
    for (const Interval& interval : overlappingIntervals) {
        cout << "[" << interval.low << ", " << interval.high << "] ";
    }
    cout << endl;

    // Delete an interval from the interval tree
    Interval deleteInterval(15, 20);
    intervalTree.deleteInterval(deleteInterval);

    // Search again after deletion
    overlappingIntervals = intervalTree.search(searchInterval);

    // Output the overlapping intervals after deletion
    cout << "Overlapping Intervals after Deletion with [" << searchInterval.low << ", " << searchInterval.high << "]:" << endl;
    for (const Interval& interval : overlappingIntervals) {
        cout << "[" << interval.low << ", " << interval.high << "] ";
    }
    cout << endl;

    return 0;
}
