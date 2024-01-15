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

vector<int> topologicalSort(vector<int> adj[], int start, int V)
{
    int indegree[V] = {0};
    for (int i = start; i <= V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> dq;

    for (int i = start; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            dq.push(i);
        }
    }

    vector<int> topo;

    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop();

        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                dq.push(it);
            }
        }
    }
    return topo;
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

    vector<int> answer = topologicalSort(adj, 1, nodes);

    for (int it : answer)
    {
        cout << it << " ";
    }

    return 0;
}
// node 1 -->
// node 2 --> 3
// node 3 --> 1
// node 4 --> 1 0
// node 5 --> 2 0
// node 6 -->