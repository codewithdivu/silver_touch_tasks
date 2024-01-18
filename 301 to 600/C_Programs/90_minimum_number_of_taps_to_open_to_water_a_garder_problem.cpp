#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minTaps(int n, vector<int> &ranges)
{

    vector<int> dp(n + 1, 0);

    for (int i = 0; i <= n; ++i)
    {
        int left = max(0, i - ranges[i]);
        int right = min(n, i + ranges[i]);
        dp[left] = max(dp[left], right);
    }

    int taps = 0;
    int farthest = 0;
    int currentEnd = 0;

    for (int i = 0; i <= n; ++i)
    {
        farthest = max(farthest, dp[i]);

        if (i == currentEnd)
        {

            if (i < n)
            {
                if (farthest <= i)
                {

                    return -1;
                }
                ++taps;
                currentEnd = farthest;
            }
            else
            {

                return taps;
            }
        }
    }

    return -1;
}

int main()
{

    int n = 7;
    vector<int> ranges = {1, 2, 1, 0, 2, 1, 0, 1};

    int result = minTaps(n, ranges);

    if (result != -1)
    {
        cout << "Minimum number of taps to water the garden: " << result << endl;
    }
    else
    {
        cout << "The garden cannot be fully watered." << endl;
    }

    return 0;
}
