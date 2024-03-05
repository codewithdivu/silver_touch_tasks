#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kadane(const vector<int> &nums)
{
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int maxSubarraySumCircular(const vector<int> &nums)
{
    int n = nums.size();

    int nonCircularSum = kadane(nums);

    int totalSum = 0;
    for (int num : nums)
    {
        totalSum += num;
    }

    vector<int> negated(nums.begin(), nums.end());
    transform(negated.begin(), negated.end(), negated.begin(), negate<int>());
    int minSubarraySum = kadane(negated);

    int circularSum = totalSum + minSubarraySum;

    return max(nonCircularSum, circularSum);
}

int main()
{
    vector<int> nums = {1, -2, 3, -2};

    int result = maxSubarraySumCircular(nums);

    cout << "Maximum Subarray Sum Circular: " << result << endl;

    return 0;
}
