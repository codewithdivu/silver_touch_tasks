#include <iostream>
#include <vector>

using namespace std;

int minJumps(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
    {
        return 0;
    }

    int maxReach = nums[0];
    int steps = nums[0];
    int jumps = 1;

    for (int i = 1; i < n - 1; ++i)
    {
        maxReach = max(maxReach, i + nums[i]);

        steps--;

        if (steps == 0)
        {
            jumps++;
            if (i >= maxReach)
            {
                return -1;
            }

            steps = maxReach - i;
        }
    }

    return jumps;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};

    int result = minJumps(nums);

    if (result != -1)
    {
        cout << "Minimum number of jumps to reach the end: " << result << endl;
    }
    else
    {
        cout << "Cannot reach the end." << endl;
    }

    return 0;
}
