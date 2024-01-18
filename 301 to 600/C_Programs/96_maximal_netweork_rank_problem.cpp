#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<unordered_set<int>> adjacencyList(n);

    for (const auto &road : roads)
    {
        adjacencyList[road[0]].insert(road[1]);
        adjacencyList[road[1]].insert(road[0]);
    }

    int maxRank = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int rank = adjacencyList[i].size() + adjacencyList[j].size();

            if (adjacencyList[i].count(j) || adjacencyList[j].count(i))
            {
                rank--;
            }

            maxRank = max(maxRank, rank);
        }
    }

    return maxRank;
}

int main()
{

    int n = 4;
    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}};

    int result = maximalNetworkRank(n, roads);

    cout << "Maximal Network Rank: " << result << endl;

    return 0;
}
