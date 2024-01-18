#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int NIL = 0;
const int INF = numeric_limits<int>::max();

class BipartiteGraph
{
private:
    int numLeftVertices, numRightVertices;
    vector<vector<int>> adjacencyList;
    vector<int> pairU, pairV, dist;

public:
    BipartiteGraph(int leftVertices, int rightVertices)
        : numLeftVertices(leftVertices), numRightVertices(rightVertices),
          adjacencyList(leftVertices + 1), pairU(leftVertices + 1, NIL),
          pairV(rightVertices + 1, NIL), dist(leftVertices + 1) {}

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
    }

    int hopcroftKarp()
    {
        int matching = 0;

        while (bfs())
        {
            for (int u = 1; u <= numLeftVertices; ++u)
            {
                if (pairU[u] == NIL && dfs(u))
                {
                    ++matching;
                }
            }
        }

        return matching;
    }

private:
    bool bfs()
    {
        queue<int> q;

        for (int u = 1; u <= numLeftVertices; ++u)
        {
            if (pairU[u] == NIL)
            {
                dist[u] = 0;
                q.push(u);
            }
            else
            {
                dist[u] = INF;
            }
        }

        dist[NIL] = INF;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[NIL])
            {
                for (int v : adjacencyList[u])
                {
                    if (dist[pairV[v]] == INF)
                    {
                        dist[pairV[v]] = dist[u] + 1;
                        q.push(pairV[v]);
                    }
                }
            }
        }

        return dist[NIL] != INF;
    }

    bool dfs(int u)
    {
        if (u != NIL)
        {
            for (int v : adjacencyList[u])
            {
                if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }

            dist[u] = INF;
            return false;
        }

        return true;
    }
};

int main()
{
    int numLeftVertices, numRightVertices, numEdges;
    cout << "Enter the number of left vertices, right vertices, and edges: ";
    cin >> numLeftVertices >> numRightVertices >> numEdges;

    BipartiteGraph bipartiteGraph(numLeftVertices, numRightVertices);

    cout << "Enter the edges (left vertex right vertex):\n";
    for (int i = 0; i < numEdges; ++i)
    {
        int u, v;
        cin >> u >> v;
        bipartiteGraph.addEdge(u, v);
    }

    int maxMatching = bipartiteGraph.hopcroftKarp();

    cout << "Maximum Cardinality Bipartite Matching: " << maxMatching << endl;

    return 0;
}
