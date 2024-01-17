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

void dfs(vector<int> adj[], int start, vector<int> &visited, stack<int> &st)
{
    visited[start] = 1;

    for (auto it : adj[start])
    {
        if (!visited[it])
        {
            dfs(adj, it, visited, st);
        }
    }
    st.push(start);
}
void dfs2(vector<int> adj[], int start, vector<int> &visited)
{
    visited[start] = 1;

    for (auto it : adj[start])
    {
        if (!visited[it])
        {
            dfs2(adj, it, visited);
        }
    }
}

int kosaraju(vector<int> adj[], int start, int V)
{
    vector<int> visited(V + 1, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, visited, st);
        }
    }

    vector<int> adjT[V + 1];

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    int scc = 0;
    vector<int> visited2(V + 1, 0);
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited2[node])
        {
            scc++;
            dfs2(adjT, node, visited2);
        }
    }
    return scc;
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
    }

    print(adj, nodes);

    int answer = kosaraju(adj, 1, nodes);

    cout << answer << " is the strongly connected components there is graph" << endl;

    return 0;
}
