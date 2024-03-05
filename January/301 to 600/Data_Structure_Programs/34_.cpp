#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacencyList;

    void topologicalSortDFS(int v, vector<bool> &visited, stack<int> &result)
    {
        visited[v] = true;

        for (int neighbor : adjacencyList[v])
        {
            if (!visited[neighbor])
            {
                topologicalSortDFS(neighbor, visited, result);
            }
        }

        result.push(v);
    }

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
    }

    vector<int> topologicalSort()
    {
        vector<bool> visited(vertices, false);
        stack<int> result;

        for (int i = 0; i < vertices; ++i)
        {
            if (!visited[i])
            {
                topologicalSortDFS(i, visited, result);
            }
        }

        vector<int> topologicalOrder;
        while (!result.empty())
        {
            topologicalOrder.push_back(result.top());
            result.pop();
        }

        return topologicalOrder;
    }
};

int main()
{

    Graph graph(6);
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    cout << "Topological Sorting Order: ";
    vector<int> result = graph.topologicalSort();

    for (int vertex : result)
    {
        cout << vertex << " ";
    }

    return 0;
}
