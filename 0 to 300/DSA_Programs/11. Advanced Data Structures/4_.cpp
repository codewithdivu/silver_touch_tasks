#include <iostream>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void buildTree(int node, int start, int end)
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

            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    int query(int node, int start, int end, int left, int right)
    {
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
    SegmentTree(const vector<int> &input)
    {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

    int rangeSumQuery(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

int main()
{
    vector<int> input = {1, 3, 5, 7, 9, 11};
    SegmentTree segmentTree(input);

    cout << "Range Sum (0 to 2): " << segmentTree.rangeSumQuery(0, 2) << endl;
    cout << "Range Sum (2 to 5): " << segmentTree.rangeSumQuery(2, 5) << endl;
    cout << "Range Sum (1 to 4): " << segmentTree.rangeSumQuery(1, 4) << endl;

    return 0;
}
