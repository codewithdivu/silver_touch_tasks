#include <iostream>
#include <vector>

using namespace std;

string longestCommonSubstring(const string &str1, const string &str2)
{
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    if (maxLength == 0)
    {
        return ""; 
    }

    return str1.substr(endIndex - maxLength + 1, maxLength);
}

int main()
{
    string str1 = "ABCXYZ";
    string str2 = "XYZABC";

    string result = longestCommonSubstring(str1, str2);

    if (result.empty())
    {
        cout << "No common substring found.\n";
    }
    else
    {
        cout << "Longest Common Substring: " << result << "\n";
    }

    return 0;
}
