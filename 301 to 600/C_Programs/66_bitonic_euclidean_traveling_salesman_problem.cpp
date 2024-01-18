#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

double euclideanDistance(pair<int, int> point1, pair<int, int> point2)
{
    return sqrt(pow(point1.first - point2.first, 2) + pow(point1.second - point2.second, 2));
}

double bitonicEuclideanTSP(vector<pair<int, int>> &points)
{
    int n = points.size();

    sort(points.begin(), points.end());

    vector<vector<double>> dp(n, vector<double>(n, numeric_limits<double>::infinity()));

    dp[0][0] = 0;

    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            for (int k = 0; k < i; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[k][i] + euclideanDistance(points[k], points[j]));
            }
        }
    }

    double minCost = numeric_limits<double>::infinity();
    for (int i = 1; i < n; ++i)
    {
        minCost = min(minCost, dp[i][n - 1] + euclideanDistance(points[i], points[n - 1]));
    }

    return minCost;
}

int main()
{

    vector<pair<int, int>> points = {{0, 0}, {1, 2}, {3, 4}, {5, 2}, {6, 1}, {8, 3}, {9, 6}, {10, 5}};

    double optimalCost = bitonicEuclideanTSP(points);

    cout << "Optimal Bitonic Euclidean TSP Cost: " << optimalCost << endl;

    return 0;
}
