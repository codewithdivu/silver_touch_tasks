#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class BipartiteGraph
{
private:
    int leftVertices;
    int rightVertices;
    vector<vector<int>> adjList;
    vector<int> leftMatching;
    vector<int> rightMatching;
    vector<int> dist;

public:
    BipartiteGraph(int left, int right) : leftVertices(left), rightVertices(right),
                                          adjList(left + right), leftMatching(left, -1), rightMatching(right, -1), dist(left) {}

    void addEdge(int leftVertex, int rightVertex)
    {
        adjList[leftVertex].push_back(leftVertices + rightVertex);
    }

    bool bfs()
    {
        queue<int> q;

        for (int i = 0; i < leftVertices; ++i)
        {
            if (leftMatching[i] == -1)
            {
                dist[i] = 0;
                q.push(i);
            }
            else
            {
                dist[i] = numeric_limits<int>::max();
            }
        }

        dist[numeric_limits<int>::max()] = numeric_limits<int>::max();

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[numeric_limits<int>::max()])
            {
                for (int v : adjList[u])
                {
                    if (dist[rightMatching[v - leftVertices]] == numeric_limits<int>::max())
                    {
                        dist[rightMatching[v - leftVertices]] = dist[u] + 1;
                        q.push(rightMatching[v - leftVertices]);
                    }
                }
            }
        }

        return (dist[numeric_limits<int>::max()] != numeric_limits<int>::max());
    }

    bool dfs(int u)
    {
        if (u != numeric_limits<int>::max())
        {
            for (int v : adjList[u])
            {
                if (dist[rightMatching[v - leftVertices]] == dist[u] + 1 && dfs(rightMatching[v - leftVertices]))
                {
                    leftMatching[u] = v;
                    rightMatching[v - leftVertices] = u;
                    return true;
                }
            }

            dist[u] = numeric_limits<int>::max();
            return false;
        }

        return true;
    }

    int hopcroftKarp()
    {
        int matchingSize = 0;

        while (bfs())
        {
            for (int i = 0; i < leftVertices; ++i)
            {
                if (leftMatching[i] == -1 && dfs(i))
                {
                    matchingSize++;
                }
            }
        }

        return matchingSize;
    }
};

int main()
{

    int leftVertices = 4;
    int rightVertices = 3;

    BipartiteGraph graph(leftVertices, rightVertices);

    graph.addEdge(0, 0);
    graph.addEdge(0, 1);
    graph.addEdge(1, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 2);
    graph.addEdge(3, 0);

    int maxMatchingSize = graph.hopcroftKarp();

    cout << "Maximum Cardinality Matching Size: " << maxMatchingSize << endl;

    return 0;
}
