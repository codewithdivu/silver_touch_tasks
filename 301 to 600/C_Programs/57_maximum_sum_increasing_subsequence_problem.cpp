#include <iostream>
#include <vector>

using namespace std;

int maxSumIncreasingSubsequence(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp = nums;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j] && dp[i] < dp[j] + nums[i])
            {
                dp[i] = dp[j] + nums[i];
            }
        }
    }

    int maxSum = dp[0];
    for (int i = 1; i < n; ++i)
    {
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {1, 101, 2, 3, 100, 4, 5};

    int result = maxSumIncreasingSubsequence(nums);

    cout << "Maximum Sum Increasing Subsequence: " << result << endl;

    return 0;
}
