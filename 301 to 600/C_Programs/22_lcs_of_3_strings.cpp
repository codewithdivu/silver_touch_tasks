#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int lcsOfThreeStrings(const string &str1, const string &str2, const string &str3)
{
    int m = str1.size();
    int n = str2.size();
    int o = str3.size();

    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(o + 1, 0)));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= o; ++k)
            {
                if (str1[i - 1] == str2[j - 1] && str1[i - 1] == str3[k - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }

    return dp[m][n][o];
}

int main()
{
    string str1, str2, str3;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    cout << "Enter the third string: ";
    cin >> str3;

    int result = lcsOfThreeStrings(str1, str2, str3);

    cout << "Length of the Longest Common Subsequence: " << result << endl;

    return 0;
}
