#include <bits/stdc++.h>
using namespace std;

int recursive(vector<int> arr, int target)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = recursive(arr, target - arr[i]);

        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

int memoization(vector<int> arr, int target, vector<int> &dp)
{
    if (target == 0)
        return 0;
    if (target < 0)
        return INT_MAX;

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = memoization(arr, target - arr[i], dp);

        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    dp[target] = mini;
    return dp[target];
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3};
    int target = 5;

    // int ans = recursive(arr, target);
    // cout << "answer is " << ans << endl;

    vector<int> dp(target + 1, -1);
    int ans = memoization(arr, target, dp);
    cout << "answer is " << ans << endl;

    return 0;
}