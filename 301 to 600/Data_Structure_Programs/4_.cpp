#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<int> visited(n + 1, -1);
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (auto &edge : edges)
    {
        int from = edge[0], to = edge[1], weight = edge[2];
        graph[from][to] = graph[to][from] = weight;
    }

    int minReachableCities = INF, minCity = -1;
    for (int city = 0; city < n; ++city)
    {
        vector<int> distances(n, INF);
        distances[city] = 0;

        for (int i = 0; i < n; ++i)
        {
            int closest = -1;
            for (int j = 0; j < n; ++j)
            {
                if (!visited[j] && (closest == -1 || distances[j] < distances[closest]))
                {
                    closest = j;
                }
            }

            visited[closest] = true;
            for (int neighbor = 0; neighbor < n; ++neighbor)
            {
                distances[neighbor] = min(distances[neighbor], distances[closest] + graph[closest][neighbor]);
            }
        }

        int reachableCities = count_if(distances.begin(), distances.end(), [&](int dist)
                                       { return dist <= distanceThreshold; });
        if (reachableCities < minReachableCities)
        {
            minReachableCities = reachableCities;
            minCity = city;
        }
    }

    return minCity;
}

int main()
{
    int n = 4, distanceThreshold = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};

    cout << "City with the smallest number of neighbors at a threshold distance of " << distanceThreshold << ": " << findTheCity(n, edges, distanceThreshold) << endl;

    return 0;
}