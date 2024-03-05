#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Subset
{
    int parent, rank;
};

class Graph
{
private:
    int V;
    int E;
    vector<Edge> edges;

public:
    Graph(int vertices, int edgesCount) : V(vertices), E(edgesCount) {}

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    int find(Subset subsets[], int i)
    {
        if (subsets[i].parent != i)
        {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void Union(Subset subsets[], int x, int y)
    {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank)
        {
            subsets[xroot].parent = yroot;
        }
        else if (subsets[xroot].rank > subsets[yroot].rank)
        {
            subsets[yroot].parent = xroot;
        }
        else
        {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    void boruvkaMST()
    {
        Subset *subsets = new Subset[V];
        vector<int> cheapest(V, -1);

        for (int i = 0; i < V; i++)
        {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        int numTrees = V;
        int MSTweight = 0;

        while (numTrees > 1)
        {
            fill_n(cheapest.begin(), V, -1);

            for (int i = 0; i < E; i++)
            {
                int set1 = find(subsets, edges[i].src);
                int set2 = find(subsets, edges[i].dest);

                if (set1 != set2)
                {
                    if (cheapest[set1] == -1 || edges[cheapest[set1]].weight > edges[i].weight)
                    {
                        cheapest[set1] = i;
                    }

                    if (cheapest[set2] == -1 || edges[cheapest[set2]].weight > edges[i].weight)
                    {
                        cheapest[set2] = i;
                    }
                }
            }

            for (int i = 0; i < V; i++)
            {
                if (cheapest[i] != -1)
                {
                    int set1 = find(subsets, edges[cheapest[i]].src);
                    int set2 = find(subsets, edges[cheapest[i]].dest);

                    if (set1 != set2)
                    {
                        cout << "Edge " << edges[cheapest[i]].src << " - " << edges[cheapest[i]].dest
                             << " has weight " << edges[cheapest[i]].weight << " included in MST\n";
                        MSTweight += edges[cheapest[i]].weight;
                        Union(subsets, set1, set2);
                        numTrees--;
                    }
                }
            }
        }

        cout << "Weight of Minimum Spanning Tree: " << MSTweight << endl;
        delete[] subsets;
    }
};

int main()
{

    Graph g(4, 5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.boruvkaMST();

    return 0;
}
