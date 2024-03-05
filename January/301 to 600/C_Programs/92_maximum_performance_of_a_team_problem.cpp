#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct Engineer
{
    int speed;
    int efficiency;

    Engineer(int s, int e) : speed(s), efficiency(e) {}
};

struct CompareEfficiency
{
    bool operator()(const Engineer &e1, const Engineer &e2) const
    {
        return e1.efficiency > e2.efficiency;
    }
};

int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
{

    vector<Engineer> engineers;
    for (int i = 0; i < n; ++i)
    {
        engineers.emplace_back(speed[i], efficiency[i]);
    }

    sort(engineers.begin(), engineers.end(), CompareEfficiency());

    priority_queue<int, vector<int>, greater<int>> minHeap;

    long long totalSpeed = 0;
    long long maxPerformance = 0;

    for (const Engineer &engineer : engineers)
    {
        totalSpeed += engineer.speed;
        minHeap.push(engineer.speed);

        if (minHeap.size() > k)
        {
            totalSpeed -= minHeap.top();
            minHeap.pop();
        }

        maxPerformance = max(maxPerformance, totalSpeed * engineer.efficiency);
    }

    return maxPerformance % 1000000007;
}

int main()
{

    int n = 6;
    vector<int> speed = {2, 10, 3, 1, 5, 8};
    vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 3;

    int result = maxPerformance(n, speed, efficiency, k);

    cout << "Maximum Performance: " << result << endl;

    return 0;
}
