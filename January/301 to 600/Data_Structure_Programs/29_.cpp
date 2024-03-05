#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    vector<int> lazy;
    int size;

    void propagate(int index, int left, int right)
    {
        if (lazy[index] != 0)
        {

            tree[index] += (right - left + 1) * lazy[index];

            if (left != right)
            {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }

            lazy[index] = 0;
        }
    }

    void updateRangeUtil(int index, int left, int right, int start, int end, int delta)
    {

        propagate(index, left, right);

        if (left > end || right < start)
        {
            return;
        }

        if (left >= start && right <= end)
        {
            tree[index] += (right - left + 1) * delta;

            if (left != right)
            {
                lazy[2 * index + 1] += delta;
                lazy[2 * index + 2] += delta;
            }

            return;
        }

        int mid = (left + right) / 2;
        updateRangeUtil(2 * index + 1, left, mid, start, end, delta);
        updateRangeUtil(2 * index + 2, mid + 1, right, start, end, delta);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int queryRangeUtil(int index, int left, int right, int start, int end)
    {

        propagate(index, left, right);

        if (left > end || right < start)
        {
            return 0;
        }

        if (left >= start && right <= end)
        {
            return tree[index];
        }

        int mid = (left + right) / 2;
        int leftSum = queryRangeUtil(2 * index + 1, left, mid, start, end);
        int rightSum = queryRangeUtil(2 * index + 2, mid + 1, right, start, end);

        return leftSum + rightSum;
    }

public:
    SegmentTree(const vector<int> &input)
    {
        size = input.size();

        int height = (int)ceil(log2(size));

        int treeSize = 2 * (int)pow(2, height) - 1;

        tree.resize(treeSize, 0);
        lazy.resize(treeSize, 0);

        buildTree(input, 0, 0, size - 1);
    }

    int buildTree(const vector<int> &input, int index, int left, int right)
    {
        if (left == right)
        {

            tree[index] = input[left];
            return input[left];
        }

        int mid = (left + right) / 2;

        tree[index] = buildTree(input, 2 * index + 1, left, mid) + buildTree(input, 2 * index + 2, mid + 1, right);
        return tree[index];
    }

    void updateRange(int start, int end, int delta)
    {
        updateRangeUtil(0, 0, size - 1, start, end, delta);
    }

    int queryRange(int start, int end)
    {
        return queryRangeUtil(0, 0, size - 1, start, end);
    }
};

int main()
{
    vector<int> input = {1, 3, 5, 7, 9, 11};

    SegmentTree segmentTree(input);

    cout << "Original array: ";
    for (int num : input)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Sum in range [1, 3]: " << segmentTree.queryRange(1, 3) << endl;

    segmentTree.updateRange(1, 2, 2);

    cout << "Updated array: ";
    for (int i = 0; i < input.size(); ++i)
    {
        input[i] += 2;
        cout << input[i] << " ";
    }
    cout << endl;

    cout << "Sum in range [1, 3] after update: " << segmentTree.queryRange(1, 3) << endl;

    return 0;
}
