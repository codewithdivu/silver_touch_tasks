#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int connectSticks(vector<int> &sticks)
{

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int stick : sticks)
    {
        minHeap.push(stick);
    }

    int totalCost = 0;

    while (minHeap.size() > 1)
    {

        int firstStick = minHeap.top();
        minHeap.pop();
        int secondStick = minHeap.top();
        minHeap.pop();

        int newStick = firstStick + secondStick;
        totalCost += newStick;

        minHeap.push(newStick);
    }

    return totalCost;
}

int main()
{

    vector<int> sticks = {2, 4, 3};
    int minCost = connectSticks(sticks);

    cout << "Minimum Cost to Connect Sticks: " << minCost << endl;

    return 0;
}
