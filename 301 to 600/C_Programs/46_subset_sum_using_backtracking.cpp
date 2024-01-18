#include <iostream>
#include <vector>

using namespace std;

bool subsetSumHelper(const vector<int> &nums, int target, int currentIndex, int currentSum)
{

    if (currentSum == target)
    {
        return true;
    }

    if (currentIndex == nums.size() || currentSum > target)
    {
        return false;
    }

    if (subsetSumHelper(nums, target, currentIndex + 1, currentSum + nums[currentIndex]))
    {
        return true;
    }

    return subsetSumHelper(nums, target, currentIndex + 1, currentSum);
}

bool subsetSum(const vector<int> &nums, int target)
{
    return subsetSumHelper(nums, target, 0, 0);
}

int main()
{
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int target = 9;

    if (subsetSum(nums, target))
    {
        cout << "There exists a subset with the sum " << target << ".\n";
    }
    else
    {
        cout << "No subset with the sum " << target << " exists.\n";
    }

    return 0;
}
