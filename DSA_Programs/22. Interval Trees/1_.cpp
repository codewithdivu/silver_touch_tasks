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
    int maxHigh;  
    Node* left;
    Node* right;

    Node(Interval i) : interval(i), maxHigh(i.high), left(nullptr), right(nullptr) {}
};

class IntervalTree {
private:
    Node* root;

public:
    IntervalTree() : root(nullptr) {}

    
    void insert(Interval i) {
        root = insertUtil(root, i);
    }

    
    void deleteInterval(Interval i) {
        root = deleteUtil(root, i);
    }

    
    vector<Interval> search(Interval i) {
        vector<Interval> result;
        searchUtil(root, i, result);
        return result;
    }

private:
    
    Node* insertUtil(Node* root, Interval i) {
        if (root == nullptr) {
            return new Node(i);
        }

        
        root->maxHigh = max(root->maxHigh, i.high);

        
        if (i.low < root->interval.low) {
            root->left = insertUtil(root->left, i);
        } else {
            root->right = insertUtil(root->right, i);
        }

        return root;
    }

    
    Node* deleteUtil(Node* root, Interval i) {
        if (root == nullptr) {
            return nullptr;
        }

        
        if (i.low < root->interval.low) {
            root->left = deleteUtil(root->left, i);
        }
        
        else if (i.low > root->interval.low) {
            root->right = deleteUtil(root->right, i);
        }
        
        else {
            
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            
            
            Node* successor = findMin(root->right);
            root->interval = successor->interval;

            
            root->right = deleteUtil(root->right, successor->interval);
        }

        
        root->maxHigh = max(getMaxHigh(root->left), getMaxHigh(root->right));

        return root;
    }

    
    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    
    int getMaxHigh(Node* root) {
        return (root != nullptr) ? root->maxHigh : INT_MIN;
    }

    
    void searchUtil(Node* root, Interval i, vector<Interval>& result) {
        if (root == nullptr) {
            return;
        }

        
        if (i.low <= root->interval.high && root->interval.low <= i.high) {
            result.push_back(root->interval);
        }

        
        
        if (root->left != nullptr && i.low <= root->left->maxHigh) {
            searchUtil(root->left, i, result);
        }

        
        searchUtil(root->right, i, result);
    }
};

int main() {
    IntervalTree intervalTree;

    
    intervalTree.insert(Interval(15, 20));
    intervalTree.insert(Interval(10, 30));
    intervalTree.insert(Interval(5, 20));
    intervalTree.insert(Interval(12, 15));
    intervalTree.insert(Interval(17, 19));
    intervalTree.insert(Interval(30, 40));

    
    Interval searchInterval(14, 16);
    vector<Interval> overlappingIntervals = intervalTree.search(searchInterval);

    
    cout << "Overlapping Intervals with [" << searchInterval.low << ", " << searchInterval.high << "]:" << endl;
    for (const Interval& interval : overlappingIntervals) {
        cout << "[" << interval.low << ", " << interval.high << "] ";
    }
    cout << endl;

    
    Interval deleteInterval(15, 20);
    intervalTree.deleteInterval(deleteInterval);

    
    overlappingIntervals = intervalTree.search(searchInterval);

    
    cout << "Overlapping Intervals after Deletion with [" << searchInterval.low << ", " << searchInterval.high << "]:" << endl;
    for (const Interval& interval : overlappingIntervals) {
        cout << "[" << interval.low << ", " << interval.high << "] ";
    }
    cout << endl;

    return 0;
}
