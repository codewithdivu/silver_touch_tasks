#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    int n;

    void build(const vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int left, int right)
    {
        if (right < start || left > end)
        {
            return INT_MAX;
        }
        if (left <= start && right >= end)
        {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftMin = query(2 * node + 1, start, mid, left, right);
        int rightMin = query(2 * node + 2, mid + 1, end, left, right);

        return min(leftMin, rightMin);
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        if (n > 0)
        {
            int height = static_cast<int>(ceil(log2(n)));
            int maxSize = 2 * static_cast<int>(pow(2, height)) - 1;
            tree.resize(maxSize, INT_MAX);
            build(arr, 0, 0, n - 1);
        }
    }

    int rangeMinimumQuery(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }
};

int main()
{

    vector<int> arr = {4, 2, 7, 1, 3, 6, 9, 8};

    SegmentTree rmqTree(arr);

    int result = rmqTree.rangeMinimumQuery(1, 5);

    cout << "Minimum in the range [1, 5]: " << result << endl;

    return 0;
}
