#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
    unordered_map<int, list<int>> adj;

public:
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void removeVertex(int key)
    {
        adj.erase(key);
    }
};

int main()
{
    int nodes, edges;
    cout << "enter no of nodes" << endl;
    cin >> nodes;

    graph g;

    for (int i = 0; i < nodes; i++)
    {
        int u, v;
        cout << "enter node ";
        cin >> u;
        cout << "enter the edge from node " << u << " to ";
        cin >> v;

        g.addEdge(u, v, 0);
    }

    g.print();
    g.removeVertex(3);
    g.print();

    return 0;
}