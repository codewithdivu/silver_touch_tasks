#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rodCutting(int length, const vector<int> &prices)
{
    vector<int> dp(length + 1, 0);

    for (int i = 1; i <= length; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[i] = max(dp[i], prices[j] + dp[i - j]);
        }
    }

    return dp[length];
}

int main()
{
    int length;
    cout << "Enter the length of the rod: ";
    cin >> length;

    vector<int> prices(length + 1);
    cout << "Enter the prices for each piece of the rod:\n";
    for (int i = 1; i <= length; ++i)
    {
        cin >> prices[i];
    }

    int maxRevenue = rodCutting(length, prices);

    cout << "Maximum revenue: " << maxRevenue << endl;

    return 0;
}
