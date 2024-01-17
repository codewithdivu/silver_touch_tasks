#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int to, capacity, flow;
};

// Ford-Fulkerson algorithm using Edmonds-Karp method
int fordFulkerson(vector<vector<Edge>> &graph, int source, int sink)
{
    int nodes = graph.size();
    vector<vector<int>> residualCapacity(nodes, vector<int>(nodes, 0));

    for (int u = 0; u < nodes; ++u)
    {
        for (const Edge &edge : graph[u])
        {
            residualCapacity[u][edge.to] = edge.capacity;
        }
    }

    vector<int> parent(nodes, -1);
    int maxFlow = 0;

    while (true)
    {
        queue<pair<int, int>> q;
        q.push({source, INF});
        fill(parent.begin(), parent.end(), -1);

        while (!q.empty())
        {
            int u = q.front().first;
            int minCapacity = q.front().second;
            q.pop();

            for (const Edge &edge : graph[u])
            {
                int v = edge.to;
                if (parent[v] == -1 && residualCapacity[u][v] > 0)
                {
                    int newMinCapacity = min(minCapacity, residualCapacity[u][v]);
                    parent[v] = u;
                    if (v == sink)
                    {
                        maxFlow += newMinCapacity;
                        int curr = v;
                        while (curr != source)
                        {
                            int prev = parent[curr];
                            residualCapacity[prev][curr] -= newMinCapacity;
                            residualCapacity[curr][prev] += newMinCapacity;
                            curr = prev;
                        }
                        break;
                    }
                    q.push({v, newMinCapacity});
                }
            }
        }

        if (parent[sink] == -1)
        {
            break;
        }
    }

    return maxFlow;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<Edge>> graph(nodes);

    cout << "Enter the edges (source destination capacity):" << endl;
    for (int i = 0; i < edges; ++i)
    {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u].push_back({v, capacity, 0});
        // Uncomment the next line if the graph is undirected
        // graph[v].push_back({u, capacity, 0});
    }

    int source, sink;
    cout << "Enter the source and sink nodes: ";
    cin >> source >> sink;

    int maxFlow = fordFulkerson(graph, source, sink);

    cout << "Maximum flow in the network: " << maxFlow << endl;

    return 0;
}

/*
Enter the number of nodes: 6
Enter the number of edges: 9
Enter the edges (source destination capacity):
0 1 10
0 2 10
1 2 2
1 3 4
1 4 8
2 4 9
3 5 10
4 3 6
4 5 10
Enter the source and sink nodes: 0 5

*/