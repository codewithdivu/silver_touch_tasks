#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubarraysWithGivenSum(const vector<int> &arr, int targetSum)
{
    unordered_map<int, int> prefixSumCount;
    int currentSum = 0;
    int count = 0;

    prefixSumCount[0] = 1;

    for (int num : arr)
    {
        currentSum += num;

        if (prefixSumCount.find(currentSum - targetSum) != prefixSumCount.end())
        {
            count += prefixSumCount[currentSum - targetSum];
        }

        prefixSumCount[currentSum]++;
    }

    return count;
}

int main()
{

    vector<int> arr = {10, 2, -2, -20, 10};
    int targetSum = -10;

    int result = countSubarraysWithGivenSum(arr, targetSum);

    cout << "Count of subarrays with sum " << targetSum << ": " << result << endl;

    return 0;
}
