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

void bfs(vector<int> adj[], int nodes, int start)
{
    queue<int> dq;
    vector<int> visited(nodes + 1, 0);
    visited[start] = 1;
    dq.push(start);
    while (!dq.empty())
    {
        int front = dq.front();
        dq.pop();
        cout << front << " ";
        for (auto it : adj[front])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                dq.push(it);
            }
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

    bfs(adj, nodes, 1);

    return 0;
}