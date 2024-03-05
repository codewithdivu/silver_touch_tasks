#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Graph
{
public:
    int nodes;
    vector<vector<int>> adjList;

    Graph(int n) : nodes(n), adjList(n + 1) {}

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFS(int current, vector<bool> &visited, vector<int> &component)
    {
        visited[current] = true;
        component.push_back(current);

        for (int neighbor : adjList[current])
        {
            if (!visited[neighbor])
            {
                DFS(neighbor, visited, component);
            }
        }
    }

    vector<vector<int>> findConnectedComponents()
    {
        vector<bool> visited(nodes + 1, false);
        vector<vector<int>> connectedComponents;

        for (int vertex = 1; vertex <= nodes; ++vertex)
        {
            if (!visited[vertex])
            {
                vector<int> component;
                DFS(vertex, visited, component);
                connectedComponents.push_back(component);
            }
        }

        return connectedComponents;
    }
};

int main()
{
    using namespace std;

    int nodes, edges, direction;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter 1 for a directed graph and 0 for an undirected graph: ";
    cin >> direction;

    vector<int> adj[nodes + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter a node: ";
        cin >> u;
        cout << "Enter an edge from node " << u << " to: ";
        cin >> v;

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    Graph graph(nodes);
    for (int i = 1; i <= nodes; ++i)
    {
        for (int neighbor : adj[i])
        {
            graph.addEdge(i, neighbor);
        }
    }

    vector<vector<int>> connectedComponents = graph.findConnectedComponents();

    cout << "Connected Components:" << endl;
    for (const vector<int> &component : connectedComponents)
    {
        for (int vertex : component)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Enter the number of nodes: 7
Enter the number of edges: 6
Enter 1 for a directed graph and 0 for an undirected graph: 0
Enter a node: 1
Enter an edge from node 1 to: 2
Enter a node: 2
Enter an edge from node 2 to: 3
Enter a node: 4
Enter an edge from node 4 to: 5
Enter a node: 5
Enter an edge from node 5 to: 6
Enter a node: 6
Enter an edge from node 6 to: 7
Enter a node: 3
Enter an edge from node 3 to: 7

*/