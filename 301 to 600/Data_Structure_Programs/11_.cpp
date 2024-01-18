#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int u, v, cost;

    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}

    bool operator>(const Edge &other) const
    {
        return cost > other.cost;
    }
};

int minCostToProvideWater(int N, vector<int> &wells, vector<vector<int>> &pipes)
{

    priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;

    for (int i = 0; i < N; ++i)
    {
        minHeap.push(Edge(0, i + 1, wells[i]));
    }

    for (auto &pipe : pipes)
    {
        minHeap.push(Edge(pipe[0], pipe[1], pipe[2]));
    }

    vector<int> parent(N + 1, -1);

    auto find = [&](int node)
    {
        while (parent[node] != -1)
        {
            node = parent[node];
        }
        return node;
    };

    int minCost = 0;

    while (!minHeap.empty())
    {
        Edge edge = minHeap.top();
        minHeap.pop();

        int rootU = find(edge.u);
        int rootV = find(edge.v);

        if (rootU != rootV)
        {
            parent[rootU] = rootV;
            minCost += edge.cost;
        }
    }

    return minCost;
}

int main()
{

    int N1 = 3;
    vector<int> wells1 = {1, 2, 2};
    vector<vector<int>> pipes1 = {{1, 2, 1}, {2, 3, 1}};
    cout << "Minimum cost for Example 1: " << minCostToProvideWater(N1, wells1, pipes1) << endl;

    int N2 = 4;
    vector<int> wells2 = {1, 1, 1, 1};
    vector<vector<int>> pipes2 = {{1, 2, 100}, {2, 3, 100}, {2, 4, 50}};
    cout << "Minimum cost for Example 2: " << minCostToProvideWater(N2, wells2, pipes2) << endl;

    return 0;
}
