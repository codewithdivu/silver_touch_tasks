#include <iostream>
#include <vector>

using namespace std;

class FenwickTree
{
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta)
    {
        index++;
        while (index < tree.size())
        {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int prefixSum(int index)
    {
        index++;
        int sum = 0;
        while (index > 0)
        {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    int rangeSum(int start, int end)
    {
        return prefixSum(end) - (start > 0 ? prefixSum(start - 1) : 0);
    }
};

int main()
{

    vector<int> array = {1, 3, 5, 2, 7, 8, 4};

    FenwickTree fenwickTree(array.size());

    for (int i = 0; i < array.size(); ++i)
    {
        fenwickTree.update(i, array[i]);
    }

    cout << "Prefix Sum at index 2: " << fenwickTree.prefixSum(2) << endl;
    cout << "Range Sum in [1, 4]: " << fenwickTree.rangeSum(1, 4) << endl;

    fenwickTree.update(3, 6);

    cout << "Updated Prefix Sum at index 2: " << fenwickTree.prefixSum(2) << endl;
    cout << "Updated Range Sum in [1, 4]: " << fenwickTree.rangeSum(1, 4) << endl;

    return 0;
}
