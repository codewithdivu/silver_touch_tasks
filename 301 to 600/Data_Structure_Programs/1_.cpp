#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<pair<int, int>> adj[], int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        cout << "node " << i << " --> ";
        for (auto it : adj[i])
        {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << endl;
    }
}

int krushkal(vector<pair<int, int>> adj[], int V, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V + 1, 0);

    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto itt = pq.top();
        pq.pop();
        int node = itt.second;
        int weight = itt.first;

        if (visited[node] == 1)
            continue;

        sum = sum + weight;
        visited[node] = 1;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjNodeWeight = it.second;
            if (!visited[adjNode])
            {
                pq.push({adjNodeWeight, adjNode});
            }
        }
    }
    return sum;
}

int main()
{
    int nodes, edges, direction;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter 1 for a directed graph and 0 for an undirected graph: ";
    cin >> direction;

    vector<pair<int, int>> adj[nodes + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cout << "Enter a node: ";
        cin >> u;
        cout << "Enter a destination node from node " << u << ": ";
        cin >> v;
        cout << "Enter the weight of the edge: ";
        cin >> w;

        adj[u].push_back({v, w});
        if (direction == 0)
        {
            adj[v].push_back({u, w});
        }
    }

    print(adj, nodes);

    cout << endl;

    int answer = krushkal(adj, nodes, 0);

    cout << "sum of mst is " << answer << endl;

    return 0;
}
