#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Data structure to represent an edge in the graph
struct Edge
{
    int to;       // The destination vertex
    int capacity; // The capacity of the edge
    int flow;     // The current flow through the edge
    int reverse;  // Index of the reverse edge in the residual graph
};

// Ford-Fulkerson algorithm using Edmonds-Karp method
class FordFulkerson
{
private:
    int numVertices;            // Number of vertices in the graph
    vector<vector<Edge>> graph; // Adjacency list representation of the graph
    vector<bool> visited;       // Array to mark visited vertices during BFS

public:
    FordFulkerson(int vertices) : numVertices(vertices), graph(vertices), visited(vertices) {}

    // Add an edge to the graph
    void addEdge(int from, int to, int capacity)
    {
        Edge forwardEdge = {to, capacity, 0, static_cast<int>(graph[to].size())};
        Edge reverseEdge = {from, 0, 0, static_cast<int>(graph[from].size())};

        graph[from].push_back(forwardEdge);
        graph[to].push_back(reverseEdge);
    }

    // Ford-Fulkerson algorithm
    int maxFlow(int source, int sink)
    {
        int maxFlow = 0;

        while (true)
        {
            // Reset the visited array for each iteration
            fill(visited.begin(), visited.end(), false);

            // Find an augmenting path using BFS
            int flow = findAugmentingPath(source, sink);

            // If no more augmenting paths can be found, break the loop
            if (flow == 0)
            {
                break;
            }

            // Update the residual graph by backtracking the augmenting path
            maxFlow += flow;
        }

        return maxFlow;
    }

private:
    // BFS to find an augmenting path
    int findAugmentingPath(int source, int sink)
    {
        queue<pair<int, int>> q;   // Queue for BFS
        q.push({source, INT_MAX}); // Start with the source vertex

        while (!q.empty())
        {
            int currentVertex = q.front().first;
            int minCapacity = q.front().second;
            q.pop();

            visited[currentVertex] = true;

            for (const Edge &edge : graph[currentVertex])
            {
                if (!visited[edge.to] && edge.capacity > 0)
                {
                    int newMinCapacity = min(minCapacity, edge.capacity);
                    q.push({edge.to, newMinCapacity});
                    visited[edge.to] = true;

                    // If we reached the sink, return the minimum capacity on the path
                    if (edge.to == sink)
                    {
                        return newMinCapacity;
                    }
                }
            }
        }

        return 0; // No augmenting path found
    }
};

int main()
{
    // Example usage
    FordFulkerson fordFulkerson(6);

    fordFulkerson.addEdge(0, 1, 10);
    fordFulkerson.addEdge(0, 2, 5);
    fordFulkerson.addEdge(1, 2, 15);
    fordFulkerson.addEdge(1, 3, 5);
    fordFulkerson.addEdge(2, 3, 10);
    fordFulkerson.addEdge(2, 4, 10);
    fordFulkerson.addEdge(3, 4, 5);
    fordFulkerson.addEdge(3, 5, 15);
    fordFulkerson.addEdge(4, 5, 10);

    int maxFlow = fordFulkerson.maxFlow(0, 5);

    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}
