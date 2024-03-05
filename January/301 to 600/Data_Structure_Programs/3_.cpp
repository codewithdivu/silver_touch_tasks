#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicUtil(int i, vector<int> adj[], bool visited[], bool *recStack)
{
    if (visited[i])
    {
        if (recStack[i])
        {
            return true;
        }
        return false;
    }

    visited[i] = true;

    recStack[i] = true;
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (isCyclicUtil(adj[i][j], adj, visited, recStack))
        {
            return true;
        }
    }

    recStack[i] = false;

    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
    bool visited[V];
    bool recStack[V];
    memset(visited, 0, sizeof(visited));
    memset(recStack, 0, sizeof(recStack));

    for (int i = 0; i < V; i++)
    {
        if (isCyclicUtil(i, adj, visited, recStack))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);

    if (isCyclic(adj, V))
    {
        cout << "Graph contains cycle";
    }
    else
    {
        cout << "Graph doesn't contain cycle";
    }

    return 0;
}