#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findShortestSubarray(vector<int> &nums)
{
    unordered_map<int, int> frequency;
    unordered_map<int, int> firstOccurrence;
    int maxDegree = 0;
    int minLength = INT_MAX;

    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];

        if (firstOccurrence.find(num) == firstOccurrence.end())
        {
            firstOccurrence[num] = i;
        }

        frequency[num]++;
        if (frequency[num] > maxDegree)
        {
            maxDegree = frequency[num];
            minLength = i - firstOccurrence[num] + 1;
        }
        else if (frequency[num] == maxDegree)
        {
            minLength = min(minLength, i - firstOccurrence[num] + 1);
        }
    }

    return minLength;
}

int main()
{

    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};

    int result = findShortestSubarray(nums);

    cout << "Smallest length of subarray with the same degree: " << result << endl;

    return 0;
}
