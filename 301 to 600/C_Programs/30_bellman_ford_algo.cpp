#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
    int source, destination, weight;
};

const int INF = numeric_limits<int>::max();

void bellmanFord(const vector<Edge> &edges, int V, int E, int source)
{
    vector<int> distance(V, INF);
    distance[source] = 0;

    
    for (int i = 1; i <= V - 1; ++i)
    {
        for (const Edge &edge : edges)
        {
            if (distance[edge.source] != INF && distance[edge.source] + edge.weight < distance[edge.destination])
            {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    
    for (const Edge &edge : edges)
    {
        if (distance[edge.source] != INF && distance[edge.source] + edge.weight < distance[edge.destination])
        {
            cout << "Graph contains a negative cycle!\n";
            return;
        }
    }

    
    cout << "Shortest distances from the source vertex (" << source << "):\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "To vertex " << i << ": " << distance[i] << "\n";
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter the source, destination, and weight for each edge:\n";
    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(edges, V, E, source);

    return 0;
}
