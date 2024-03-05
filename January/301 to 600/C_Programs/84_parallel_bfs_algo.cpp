#include <iostream>
#include <queue>
#include <vector>
#include <omp.h>

using namespace std;

class Graph
{
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int src, int dest)
    {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }
};

void parallelBFS(const Graph &graph, int startVertex, vector<int> &distances)
{
    int numVertices = graph.vertices;
    distances.resize(numVertices, -1);

    queue<int> q;
    distances[startVertex] = 0;
    q.push(startVertex);

    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();

#pragma omp parallel for
        for (int i = 0; i < graph.adjacencyList[currentVertex].size(); ++i)
        {
            int neighbor = graph.adjacencyList[currentVertex][i];
            if (distances[neighbor] == -1)
            {
                distances[neighbor] = distances[currentVertex] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{

    int numVertices = 8;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(4, 6);
    graph.addEdge(5, 7);
    graph.addEdge(6, 7);

    int startVertex = 0;
    vector<int> distances;

    parallelBFS(graph, startVertex, distances);

    cout << "Distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
