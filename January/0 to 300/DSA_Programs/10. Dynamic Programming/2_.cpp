#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion
int LISRecursion(int size, vector<int> arr, int curr, int prev)
{
    if (curr == size)
    {
        return 0;
    }

    // include
    int take = 0;
    if (prev == -1 || arr[curr] > arr[prev])
    {
        take = 1 + LISRecursion(size, arr, curr + 1, curr);
    }

    // exclude
    int notTake = 0 + LISRecursion(size, arr, curr + 1, prev);
    return max(take, notTake);
}

// memoization

int LISMemoization(int size, vector<int> arr, int curr, int prev, vector<vector<int>> &dp)
{
    if (curr == size)
    {
        return 0;
    }

    if (dp[curr][prev + 1])
    {
        return dp[curr][prev + 1];
    }

    // include
    int take = 0;
    if (prev == -1 || arr[curr] > arr[prev])
    {
        take = 1 + LISMemoization(size, arr, curr + 1, curr, dp);
    }

    // exclude
    int notTake = 0 + LISMemoization(size, arr, curr + 1, prev, dp);
    return dp[curr][prev + 1] = max(take, notTake);
}

// tabulation

int LISTabulation(int num, vector<int> &dp)
{
    return 1;
}

// space-optimization

int LISSpaceOptimization(int num, vector<int> &dp)
{
    return 1;
}

int main()
{
    int num = 5;
    vector<int> arr = {5, 8, 3, 7, 9, 1};
    vector<vector<int>> dp(num, vector<int>(num + 1, -1));

    cout << "Longest Subsequence of arr's length is " << LISRecursion(arr.size(), arr, 0, -1);
    cout << endl;
    cout << "Longest Subsequence of arr's length is " << LISMemoization(arr.size(), arr, 0, -1, dp);
    cout << endl;
    // cout << "Longest Subsequence of arr's length is " << LISTabulation(num, dp);
    // cout << endl;
    // cout << "Longest Subsequence of arr's length is " << LISSpaceOptimization(num, dp);

    return 0;
}