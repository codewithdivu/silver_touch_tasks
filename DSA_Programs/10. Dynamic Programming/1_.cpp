#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// recursion

int fiboRecursion(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }
    return fiboRecursion(num - 1) + fiboRecursion(num - 2);
}

// memoization

int fiboMemoization(int num, vector<int> &dp)
{
    if (num == 0 || num == 1)
    {
        return num;
    }

    if (dp[num])
    {
        return dp[num];
    }

    dp[num] = fiboMemoization(num - 1, dp) + fiboMemoization(num - 2, dp);
    return dp[num];
}

// tabulation

int fiboTabulation(int num, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= num; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[num];
}

// space-optimization

int fiboSpaceOptimization(int num, vector<int> &dp)
{
    int prev1 = 1;
    int prev2 = 0;

    for (int i = 2; i <= num; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int num = 5;
    vector<int> dp(num + 1);

    cout << num << "th fibo number is " << fiboRecursion(num);
    cout << endl;
    cout << num << "th fibo number is " << fiboMemoization(num, dp);
    cout << endl;
    cout << num << "th fibo number is " << fiboTabulation(num, dp);
    cout << endl;
    cout << num << "th fibo number is " << fiboSpaceOptimization(num, dp);

    return 0;
}