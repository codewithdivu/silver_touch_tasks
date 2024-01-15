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

bool isCycle(int start, vector<int> adj[], vector<int> visited)
{
    unordered_map<int, int> parent;

    parent[start] = -1;
    visited[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (auto it : adj[temp])
        {
            if (visited[it] && it != parent[temp])
            {
                return true;
            }
            else if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
                parent[it] = temp;
            }
        }
    }
    return false;
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

    if (isCycle(1, adj, visited))
    {
        cout << "There is Cycle in undirected graph" << endl;
    }
    else
    {
        cout << "There is no-Cycle in undirected graph" << endl;
    }

    return 0;
}