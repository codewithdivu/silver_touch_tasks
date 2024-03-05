#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    vector<int> lazy;
    int n;

    void buildTree(int node, int start, int end, const vector<int> &arr)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            buildTree(leftChild, start, mid, arr);
            buildTree(rightChild, mid + 1, end, arr);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    void updateRange(int node, int start, int end, int left, int right, int delta)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > right || end < left)
        {
            return;
        }
        else if (start >= left && end <= right)
        {
            tree[node] += (end - start + 1) * delta;

            if (start != end)
            {
                lazy[2 * node + 1] += delta;
                lazy[2 * node + 2] += delta;
            }

            return;
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            updateRange(leftChild, start, mid, left, right, delta);
            updateRange(rightChild, mid + 1, end, left, right, delta);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    int query(int node, int start, int end, int left, int right)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end)
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (start > right || end < left)
        {
            return 0;
        }
        else if (start >= left && end <= right)
        {
            return tree[node];
        }
        else
        {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            int leftSum = query(leftChild, start, mid, left, right);
            int rightSum = query(rightChild, mid + 1, end, left, right);

            return leftSum + rightSum;
        }
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(0, 0, n - 1, arr);
    }

    void rangeUpdate(int left, int right, int delta)
    {
        updateRange(0, 0, n - 1, left, right, delta);
    }

    int rangeSumQuery(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    SegmentTree segmentTree(arr);

    cout << "Original Array: {1, 2, 3, 4, 5}" << endl;
    cout << "Range Sum (0 to 2): " << segmentTree.rangeSumQuery(0, 2) << endl;

    segmentTree.rangeUpdate(1, 3, 2);

    cout << "After Range Update (Add 2 to elements in range 1 to 3):" << endl;
    cout << "Range Sum (0 to 2): " << segmentTree.rangeSumQuery(0, 2) << endl;
    cout << "Range Sum (1 to 3): " << segmentTree.rangeSumQuery(1, 3) << endl;

    return 0;
}
