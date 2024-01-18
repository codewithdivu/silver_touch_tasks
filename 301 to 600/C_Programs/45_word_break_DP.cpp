#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(const string &s, const unordered_set<string> &wordDict)
{
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true; 

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (dp[j] && wordDict.count(s.substr(j, i - j)))
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main()
{
    string s = "leetcode";
    unordered_set<string> wordDict = {"leet", "code"};

    if (wordBreak(s, wordDict))
    {
        cout << "The string can be segmented.\n";
    }
    else
    {
        cout << "The string cannot be segmented.\n";
    }

    return 0;
}
