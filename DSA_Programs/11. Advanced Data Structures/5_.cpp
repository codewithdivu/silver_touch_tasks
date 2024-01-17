#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    // Function to build the segment tree
    void buildTree(int node, int start, int end, const vector<int> &arr)
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
            buildTree(leftChild, start, mid, arr);
            buildTree(rightChild, mid + 1, end, arr);

            // Combine the results from the left and right subtrees
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Function to update a range in the segment tree
    void updateRange(int node, int start, int end, int left, int right, int delta)
    {
        // Propagate lazy updates before querying or updating
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end)
            {
                // Mark children for lazy updates
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0; // Reset lazy update for the current node
        }

        if (start > right || end < left)
        {
            // Node's range is completely outside the update range
            return;
        }
        else if (start >= left && end <= right)
        {
            // Node's range is completely inside the update range
            tree[node] += (end - start + 1) * delta;

            if (start != end)
            {
                // Mark children for lazy updates
                lazy[2 * node + 1] += delta;
                lazy[2 * node + 2] += delta;
            }

            return;
        }
        else
        {
            // Node's range partially overlaps with the update range
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            // Recursively update the left and right subtrees
            updateRange(leftChild, start, mid, left, right, delta);
            updateRange(rightChild, mid + 1, end, left, right, delta);

            // Update the current node based on the results from the left and right subtrees
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Function to query the segment tree
    int query(int node, int start, int end, int left, int right)
    {
        // Propagate lazy updates before querying or updating
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end)
            {
                // Mark children for lazy updates
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0; // Reset lazy update for the current node
        }

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
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(0, 0, n - 1, arr);
    }

    // Function to perform a range update
    void rangeUpdate(int left, int right, int delta)
    {
        updateRange(0, 0, n - 1, left, right, delta);
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
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree segmentTree(arr);

    // Perform range sum queries
    cout << "Original Array: {1, 2, 3, 4, 5}" << endl;
    cout << "Range Sum (0 to 2): " << segmentTree.rangeSumQuery(0, 2) << endl;

    // Perform range updates
    segmentTree.rangeUpdate(1, 3, 2);

    cout << "After Range Update (Add 2 to elements in range 1 to 3):" << endl;
    cout << "Range Sum (0 to 2): " << segmentTree.rangeSumQuery(0, 2) << endl;
    cout << "Range Sum (1 to 3): " << segmentTree.rangeSumQuery(1, 3) << endl;

    return 0;
}
