#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int findLCSLength(string &str1, string &str2, vector<vector<int>> &dp)
{
    int m = str1.length();
    int n = str2.length();

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

void printAllLCS(string &str1, string &str2, vector<vector<int>> &dp, int i, int j, string current, set<string> &lcsSet)
{
    if (i == 0 || j == 0)
    {
        reverse(current.begin(), current.end());
        lcsSet.insert(current);
        return;
    }

    if (str1[i - 1] == str2[j - 1])
    {
        printAllLCS(str1, str2, dp, i - 1, j - 1, current + str1[i - 1], lcsSet);
    }
    else
    {
        if (dp[i - 1][j] >= dp[i][j - 1])
        {
            printAllLCS(str1, str2, dp, i - 1, j, current, lcsSet);
        }

        if (dp[i][j - 1] >= dp[i - 1][j])
        {
            printAllLCS(str1, str2, dp, i, j - 1, current, lcsSet);
        }
    }
}

int main()
{
    string str1 = "abcabcaa";
    string str2 = "acbacba";

    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int lcsLength = findLCSLength(str1, str2, dp);

    if (lcsLength == 0)
    {
        cout << "No common subsequence found." << endl;
    }
    else
    {

        set<string> lcsSet;

        printAllLCS(str1, str2, dp, m, n, "", lcsSet);

        cout << "Longest Common Subsequences in lexicographical order:" << endl;
        for (const string &lcs : lcsSet)
        {
            cout << lcs << endl;
        }
    }

    return 0;
}
