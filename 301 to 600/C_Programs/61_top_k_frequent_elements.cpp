#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> frequencyMap;

    for (int num : nums)
    {
        frequencyMap[num]++;
    }

    auto compare = [](pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

    for (auto &entry : frequencyMap)
    {
        minHeap.push(entry);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
