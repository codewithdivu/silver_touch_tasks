#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
public:
    vector<int> parent, rank;

    UnionFind(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);

        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                swap(rootX, rootY);
            }

            parent[rootY] = rootX;

            if (rank[rootX] == rank[rootY])
            {
                rank[rootX]++;
            }
        }
    }
};

int minComponentDifference(int N, int Q, vector<vector<int>> &queries)
{
    UnionFind uf(N);
    int minDiff = N;

    for (const auto &query : queries)
    {
        int u = query[0];
        int v = query[1];

        if (uf.find(u) != uf.find(v))
        {
            uf.unionSets(u, v);
            minDiff = min(minDiff, uf.rank[uf.find(u)]);
        }
    }

    return minDiff;
}

int main()
{

    int N1 = 2, Q1 = 1;
    vector<vector<int>> queries1 = {{1, 2}};
    cout << "Minimum difference: " << minComponentDifference(N1, Q1, queries1) << endl;

    int N2 = 4, Q2 = 2;
    vector<vector<int>> queries2 = {{1, 2}, {2, 4}};
    cout << "Minimum difference: " << minComponentDifference(N2, Q2, queries2) << endl;

    return 0;
}