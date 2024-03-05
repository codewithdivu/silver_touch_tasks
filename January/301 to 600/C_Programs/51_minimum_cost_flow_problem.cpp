#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge
{
    int src, dest, capacity, cost;

    Edge(int s, int d, int cap, int cst) : src(s), dest(d), capacity(cap), cost(cst) {}
};

class MinimumCostFlow
{
private:
    int V;
    int E;
    vector<Edge> edges;

public:
    MinimumCostFlow(int vertices, int edgesCount) : V(vertices), E(edgesCount) {}

    void addEdge(int src, int dest, int capacity, int cost)
    {
        edges.push_back(Edge(src, dest, capacity, cost));
    }

    bool bellmanFord(int source, int sink, int &flow, int &cost)
    {
        vector<int> distance(V, INT_MAX);
        vector<int> parent(V, -1);

        distance[source] = 0;

        for (int i = 1; i <= V - 1; ++i)
        {
            for (const Edge &edge : edges)
            {
                if (edge.capacity > 0 && distance[edge.src] != INT_MAX &&
                    distance[edge.src] + edge.cost < distance[edge.dest])
                {
                    distance[edge.dest] = distance[edge.src] + edge.cost;
                    parent[edge.dest] = edge.src;
                }
            }
        }

        if (distance[sink] == INT_MAX)
        {
            return false;
        }

        int current = sink;
        int bottleneck = INT_MAX;

        while (parent[current] != -1)
        {
            int parentVertex = parent[current];
            for (const Edge &edge : edges)
            {
                if (edge.src == parentVertex && edge.dest == current)
                {
                    bottleneck = min(bottleneck, edge.capacity);
                    break;
                }
            }
            current = parentVertex;
        }

        current = sink;
        while (parent[current] != -1)
        {
            int parentVertex = parent[current];
            for (Edge &edge : edges)
            {
                if (edge.src == parentVertex && edge.dest == current)
                {
                    edge.capacity -= bottleneck;
                    edge.cost *= -1;
                    break;
                }
            }
            current = parentVertex;
        }

        flow += bottleneck;
        cost += bottleneck * distance[sink];

        return true;
    }

    void findMinimumCostFlow(int source, int sink)
    {
        int flow = 0;
        int cost = 0;

        while (bellmanFord(source, sink, flow, cost))
        {
        }

        cout << "Minimum Cost Flow: " << cost << endl;
    }
};

int main()
{

    MinimumCostFlow flowNetwork(4, 5);
    flowNetwork.addEdge(0, 1, 2, 1);
    flowNetwork.addEdge(0, 2, 1, 2);
    flowNetwork.addEdge(1, 2, 1, 1);
    flowNetwork.addEdge(1, 3, 1, 3);
    flowNetwork.addEdge(2, 3, 2, 1);

    flowNetwork.findMinimumCostFlow(0, 3);

    return 0;
}
