#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Graph
{
public:
    int vertices;
    vector<unordered_set<int>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    bool isCyclicUtil(int current, int parent, unordered_set<int> &visited)
    {
        visited.insert(current);

        for (int neighbor : adjList[current])
        {
            if (!visited.count(neighbor))
            {
                if (isCyclicUtil(neighbor, current, visited))
                {
                    return true;
                }
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool isCyclic()
    {
        unordered_set<int> visited;

        for (int vertex = 0; vertex < vertices; ++vertex)
        {
            if (!visited.count(vertex))
            {
                if (isCyclicUtil(vertex, -1, visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.isCyclic())
    {
        cout << "The undirected graph contains a cycle." << endl;
    }
    else
    {
        cout << "The undirected graph does not contain a cycle." << endl;
    }

    return 0;
}
