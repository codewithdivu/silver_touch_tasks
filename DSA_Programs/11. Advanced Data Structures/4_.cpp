#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    // Function to build the segment tree
    void buildTree(int node, int start, int end)
    {
        if (start == end)
        {
            // Leaf node
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Recursively build the left and right subtrees
            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);

            // Combine the results from the left and right subtrees
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Function to perform a range sum query
    int query(int node, int start, int end, int left, int right)
    {
        if (start > right || end < left)
        {
            // Node's range is completely outside the query range
            return 0;
        }
        else if (start >= left && end <= right)
        {
            // Node's range is completely inside the query range
            return tree[node];
        }
        else
        {
            // Node's range partially overlaps with the query range
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Recursively query the left and right subtrees
            int leftSum = query(leftChild, start, mid, left, right);
            int rightSum = query(rightChild, mid + 1, end, left, right);

            // Combine the results from the left and right subtrees
            return leftSum + rightSum;
        }
    }

public:
    // Constructor to initialize the segment tree
    SegmentTree(const vector<int> &input)
    {
        n = input.size();
        arr = input;
        // The size of the segment tree is at most 4 times the size of the input array
        tree.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

    // Function to perform a range sum query
    int rangeSumQuery(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

int main()
{
    // Example usage
    vector<int> input = {1, 3, 5, 7, 9, 11};
    SegmentTree segmentTree(input);

    // Perform range sum queries
    cout << "Range Sum (0 to 2): " << segmentTree.rangeSumQuery(0, 2) << endl;
    cout << "Range Sum (2 to 5): " << segmentTree.rangeSumQuery(2, 5) << endl;
    cout << "Range Sum (1 to 4): " << segmentTree.rangeSumQuery(1, 4) << endl;

    return 0;
}
