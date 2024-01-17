#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void print(vector<int> adj[], int nodes)
{
    for (int i = 1; i <= nodes; i++)
    {
        cout << "node " << i << " --> ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

void articulationDFS(vector<int> adj[], int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, set<int> &articulationPoints)
{
    static int time = 0;
    int children = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            articulationDFS(adj, v, visited, disc, low, parent, articulationPoints);

            low[u] = min(low[u], low[v]);

            if (low[v] >= disc[u] && parent[u] != -1)
            {
                articulationPoints.insert(u);
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (parent[u] == -1 && children > 1)
    {
        articulationPoints.insert(u);
    }
}

set<int> findArticulationPoints(vector<int> adj[], int nodes)
{
    vector<bool> visited(nodes + 1, false);
    vector<int> disc(nodes + 1, 0);
    vector<int> low(nodes + 1, 0);
    vector<int> parent(nodes + 1, -1);
    set<int> articulationPoints;

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            articulationDFS(adj, i, visited, disc, low, parent, articulationPoints);
        }
    }

    return articulationPoints;
}

int main()
{
    int nodes, edges, direction;
    cout << "enter no of nodes" << endl;
    cin >> nodes;
    cout << "enter no of edges" << endl;
    cin >> edges;

    vector<int> adj[nodes + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "enter a node ";
        cin >> u;
        cout << "enter a edge from node " << u << " to ";
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    print(adj, nodes);

    set<int> articulationPoints = findArticulationPoints(adj, nodes);

    cout << "Articulation points are: ";
    for (auto point : articulationPoints)
    {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}
