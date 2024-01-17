#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class FordFulkerson
{
private:
    int vertices;
    vector<vector<int>> residualGraph;

public:
    FordFulkerson(int v) : vertices(v)
    {
        residualGraph.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v, int capacity)
    {
        residualGraph[u][v] = capacity;
    }

    int fordFulkerson(int source, int sink)
    {
        int maxFlow = 0;

        while (int augmentingPathFlow = findAugmentingPath(source, sink))
        {
            maxFlow += augmentingPathFlow;
            updateResidualGraph(source, sink, augmentingPathFlow);
        }

        return maxFlow;
    }

    void findMinCut(int source, vector<bool> &reachable)
    {
        // Run DFS to find vertices reachable from the source
        dfs(source, reachable);
    }

private:
    int findAugmentingPath(int source, int sink)
    {
        vector<int> parent(vertices, -1);
        vector<int> minCapacity(vertices, INF);

        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v = 0; v < vertices; ++v)
            {
                if (parent[v] == -1 && residualGraph[u][v] > 0)
                {
                    parent[v] = u;
                    minCapacity[v] = min(minCapacity[u], residualGraph[u][v]);
                    q.push(v);

                    if (v == sink)
                    {
                        return minCapacity[sink];
                    }
                }
            }
        }

        return 0;
    }

    void updateResidualGraph(int source, int sink, int flow)
    {
        int v = sink;
        while (v != source)
        {
            int u = residualGraph[v][1];

            residualGraph[u][v] -= flow;
            residualGraph[v][u] += flow;

            v = u;
        }
    }

    void dfs(int u, vector<bool> &reachable)
    {
        reachable[u] = true;

        for (int v = 0; v < vertices; ++v)
        {
            if (!reachable[v] && residualGraph[u][v] > 0)
            {
                dfs(v, reachable);
            }
        }
    }
};

int main()
{
    // Example flow network:
    // Source (0) --2--> (1) --3--> (2) --2--> Sink (3)
    //                           \--1--> Sink (4)
    //                            \--2--> Sink (5)

    FordFulkerson fordFulkerson(6);

    fordFulkerson.addEdge(0, 1, 2);
    fordFulkerson.addEdge(1, 2, 3);
    fordFulkerson.addEdge(2, 3, 2);
    fordFulkerson.addEdge(2, 4, 1);
    fordFulkerson.addEdge(2, 5, 2);

    int maxFlow = fordFulkerson.fordFulkerson(0, 3);

    cout << "Maximum Flow: " << maxFlow << endl;

    // Find the minimum cut
    vector<bool> reachable(6, false);
    fordFulkerson.findMinCut(0, reachable);

    cout << "Minimum Cut: ";
    for (int i = 0; i < 6; ++i)
    {
        if (reachable[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
