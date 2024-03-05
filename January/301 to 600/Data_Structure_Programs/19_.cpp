#include <iostream>
#include <vector>

using namespace std;

bool canPartitionIntoKSubsets(vector<int> &nums, int K, int targetSum, vector<int> &subsetSum, int index)
{
    if (index == nums.size())
    {
        for (int sum : subsetSum)
        {
            if (sum != targetSum)
            {
                return false;
            }
        }
        return true;
    }

    for (int i = 0; i < K; ++i)
    {
        if (subsetSum[i] + nums[index] <= targetSum)
        {
            subsetSum[i] += nums[index];
            if (canPartitionIntoKSubsets(nums, K, targetSum, subsetSum, index + 1))
            {
                return true;
            }
            subsetSum[i] -= nums[index];
        }
    }

    return false;
}

bool canPartitionKSubsets(vector<int> &nums, int K)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    if (sum % K != 0)
    {
        return false;
    }

    int targetSum = sum / K;
    vector<int> subsetSum(K, 0);

    return canPartitionIntoKSubsets(nums, K, targetSum, subsetSum, 0);
}

int main()
{

    vector<int> arr1 = {2, 1, 4, 5, 6};
    int K1 = 3;

    cout << "Example 1: ";
    if (canPartitionKSubsets(arr1, K1))
    {
        cout << "Yes, the set can be partitioned into " << K1 << " subsets with equal sum." << endl;
    }
    else
    {
        cout << "No, the set cannot be partitioned into " << K1 << " subsets with equal sum." << endl;
    }

    vector<int> arr2 = {2, 1, 5, 5, 6};
    int K2 = 3;

    cout << "Example 2: ";
    if (canPartitionKSubsets(arr2, K2))
    {
        cout << "Yes, the set can be partitioned into " << K2 << " subsets with equal sum." << endl;
    }
    else
    {
        cout << "No, the set cannot be partitioned into " << K2 << " subsets with equal sum." << endl;
    }

    return 0;
}
