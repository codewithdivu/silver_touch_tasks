#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minDistance(const string &word1, const string &word2, vector<vector<int>> &dp, vector<vector<string>> &operations)
{
    int m = word1.size();
    int n = word2.size();

    dp.resize(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = j;
                operations[i][j] = string(j, 'I');
            }
            else if (j == 0)
            {
                dp[i][j] = i;
                operations[i][j] = string(i, 'D');
            }
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
                operations[i][j] = operations[i - 1][j - 1];
            }
            else
            {
                int insertCost = dp[i][j - 1] + 1;
                int deleteCost = dp[i - 1][j] + 1;
                int replaceCost = dp[i - 1][j - 1] + 1;

                dp[i][j] = min({insertCost, deleteCost, replaceCost});

                if (dp[i][j] == insertCost)
                {
                    operations[i][j] = operations[i][j - 1] + "I";
                }
                else if (dp[i][j] == deleteCost)
                {
                    operations[i][j] = operations[i - 1][j] + "D";
                }
                else
                {
                    operations[i][j] = operations[i - 1][j - 1] + "R";
                }
            }
        }
    }

    return dp[m][n];
}

void printEditOperations(const string &word1, const string &word2, const vector<vector<string>> &operations)
{
    int i = word1.size();
    int j = word2.size();

    cout << "Edit Operations:\n";

    for (const char &op : operations[i][j])
    {
        if (op == 'I')
        {
            cout << "Insert ";
            cout << word2[j - 1] << " at position " << i << "\n";
            j--;
        }
        else if (op == 'D')
        {
            cout << "Delete ";
            cout << word1[i - 1] << " at position " << i << "\n";
            i--;
        }
        else
        {
            cout << "Replace ";
            cout << word1[i - 1] << " at position " << i;
            cout << " with " << word2[j - 1] << " at position " << j << "\n";
            i--;
            j--;
        }
    }
}

int main()
{
    string word1 = "intention";
    string word2 = "execution";

    vector<vector<int>> dp;
    vector<vector<string>> operations;

    int distance = minDistance(word1, word2, dp, operations);

    cout << "Edit Distance: " << distance << "\n\n";

    printEditOperations(word1, word2, operations);

    return 0;
}
