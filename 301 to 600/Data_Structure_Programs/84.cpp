#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {

            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class DynamicGraphConnectivity
{
public:
    DynamicGraphConnectivity(int n) : uf(n) {}

    void insertEdge(int u, int v)
    {
        uf.unionSets(u, v);
    }

    void deleteEdge(int u, int v)
    {
        int rootU = uf.find(u);
        int rootV = uf.find(v);

        if (rootU == rootV)
        {

            uf.unionSets(u, u);
            uf.unionSets(v, v);
        }
    }

    bool isConnected(int u, int v)
    {
        return uf.find(u) == uf.find(v);
    }

private:
    UnionFind uf;
};

int main()
{

    DynamicGraphConnectivity dynamicGraph(5);

    dynamicGraph.insertEdge(0, 1);
    dynamicGraph.insertEdge(1, 2);
    dynamicGraph.insertEdge(3, 4);

    cout << "Is 0 connected to 2? " << (dynamicGraph.isConnected(0, 2) ? "Yes" : "No") << endl;

    dynamicGraph.deleteEdge(1, 2);

    cout << "Is 0 connected to 2 after deletion? " << (dynamicGraph.isConnected(0, 2) ? "Yes" : "No") << endl;

    return 0;
}
