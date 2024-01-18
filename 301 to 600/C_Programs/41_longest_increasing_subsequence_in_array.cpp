#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(const vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }

    vector<int> lis(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    return *max_element(lis.begin(), lis.end());
}

int main()
{
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    int length = longestIncreasingSubsequence(nums);

    cout << "Length of the Longest Increasing Subsequence: " << length << endl;

    return 0;
}
