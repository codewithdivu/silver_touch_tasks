#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element
{
    int value;
    int row;
    int col;

    Element(int v, int r, int c) : value(v), row(r), col(c) {}

    bool operator>(const Element &other) const
    {
        return value > other.value;
    }
};

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();

    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    for (int i = 0; i < n; ++i)
    {
        minHeap.push(Element(matrix[i][0], i, 0));
    }

    for (int i = 0; i < k - 1; ++i)
    {
        Element smallest = minHeap.top();
        minHeap.pop();

        if (smallest.col < n - 1)
        {
            minHeap.push(Element(matrix[smallest.row][smallest.col + 1], smallest.row, smallest.col + 1));
        }
    }

    return minHeap.top().value;
}

int main()
{

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}};

    int k = 8;
    int result = kthSmallest(matrix, k);

    cout << "Kth Smallest Element: " << result << endl;

    return 0;
}
