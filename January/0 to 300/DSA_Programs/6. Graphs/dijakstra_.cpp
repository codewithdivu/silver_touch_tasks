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

vector<int> dijakstra(vector<pair<int, int>> adj[], int V, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V);

    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.second;
            int adjWeight = it.first;
            if (distance + adjWeight < dist[adjNode])
            {
                dist[adjNode] = distance + adjWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
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

    vector<int> answer = dijakstra(adj, nodes, 0);

    for (int i = 0; i < nodes; i++)
    {
        cout << "distance from 0 to " << i << " is " << answer[i] << endl;
    }

    return 0;
}
