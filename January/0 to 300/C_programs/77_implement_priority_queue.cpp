#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{

    // --------------------MAX-HEAP------------------------------

    priority_queue<int> maxHeap;

    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);

    cout << "element at Top " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "element at Top " << maxHeap.top() << endl;

    cout << "size is " << maxHeap.size() << endl;

    if (maxHeap.empty())
    {
        cout << "maxHeap is empty" << endl;
    }
    else
    {
        cout << "maxHeap is not empty" << endl;
    }

    // --------------------MIN-HEAP------------------------------

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout << "element at Top " << minHeap.top() << endl;
    minHeap.pop();
    cout << "element at Top " << minHeap.top() << endl;

    cout << "size is " << minHeap.size() << endl;

    if (minHeap.empty())
    {
        cout << "minHeap is empty" << endl;
    }
    else
    {
        cout << "minHeap is not empty" << endl;
    }

    return 0;
}