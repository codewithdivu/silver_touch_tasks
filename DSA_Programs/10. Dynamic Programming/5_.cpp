#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(const string &str1, const string &str2)
{
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string str1 = "kitten";
    string str2 = "sitting";

    int distance = editDistance(str1, str2);

    cout << "Edit Distance between \"" << str1 << "\" and \"" << str2 << "\" is: " << distance << endl;

    return 0;
}
