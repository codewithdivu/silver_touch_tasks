#include <iostream>
#include <bits/stdc++.h>
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

void dfs(int start, vector<int> adj[], vector<int> &visited)
{
    visited[start] = 1;
    cout << start << " ";
    for (auto it : adj[start])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited);
        }
    }
}

int main()
{
    int nodes, edges, direction;
    cout << "enter no of nodes" << endl;
    cin >> nodes;
    cout << "enter no of edges" << endl;
    cin >> edges;
    cout << "enter 1 for directed graph and 0 for undirected graph" << endl;
    cin >> direction;

    vector<int> adj[nodes + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "enter a node ";
        cin >> u;
        cout << "enter a edge from node " << u << " to ";
        cin >> v;

        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    print(adj, nodes);

    vector<int> visited(nodes + 1, 0);
    dfs(1, adj, visited);

    return 0;
}