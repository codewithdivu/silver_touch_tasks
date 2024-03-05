#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> balloons(n + 2, 1);
    for (int i = 0; i < n; ++i)
    {
        balloons[i + 1] = nums[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int len = 2; len <= n + 1; ++len)
    {
        for (int left = 0; left <= n + 1 - len; ++left)
        {
            int right = left + len;
            for (int k = left + 1; k < right; ++k)
            {

                int coins = balloons[left] * balloons[k] * balloons[right];
                coins += dp[left][k] + dp[k][right];

                dp[left][right] = max(dp[left][right], coins);
            }
        }
    }

    return dp[0][n + 1];
}

int main()
{

    vector<int> balloons = {3, 1, 5, 8};

    int result = maxCoins(balloons);

    cout << "Maximum coins collected: " << result << endl;

    return 0;
}
