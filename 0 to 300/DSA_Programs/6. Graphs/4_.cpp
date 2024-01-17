#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int graph[4][4], int v, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(v);

    for (int i = 0; i < v; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (int i = 0; i < v; i++)
        {
            if (graph[node][i])
            {
                int adjNode = i;
                int adjWeight = graph[node][i];

                if (dist + adjWeight < dis[adjNode])
                {
                    dis[adjNode] = dist + adjWeight;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
    }
    return dis;
}

int main()
{
    const int numVertices = 4;

    int graph[numVertices][numVertices] = {
        {0, 2, 0, 3},
        {2, 0, 4, 0},
        {0, 4, 0, 5},
        {3, 0, 5, 0}};

    vector<int> ans = dijkstra(graph, numVertices, 0);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}