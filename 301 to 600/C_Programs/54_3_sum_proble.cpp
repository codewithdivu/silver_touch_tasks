#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 2; ++i)
    {

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int currentSum = nums[i] + nums[left] + nums[right];

            if (currentSum == target)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }

                left++;
                right--;
            }
            else if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;

    vector<vector<int>> result = threeSum(nums, target);

    cout << "Triplets with sum " << target << ":\n";
    for (const vector<int> &triplet : result)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
