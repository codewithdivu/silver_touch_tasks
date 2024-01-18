#include <iostream>
#include <vector>

using namespace std;

class WeightedUnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    WeightedUnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
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
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    bool sameSet(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{

    WeightedUnionFind uf(6);

    uf.unionSets(0, 1);
    uf.unionSets(1, 2);
    uf.unionSets(3, 4);

    cout << "Is 0 and 2 in the same set? " << (uf.sameSet(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 2 and 3 in the same set? " << (uf.sameSet(2, 3) ? "Yes" : "No") << endl;

    uf.unionSets(2, 3);

    cout << "Is 0 and 3 in the same set? " << (uf.sameSet(0, 3) ? "Yes" : "No") << endl;

    return 0;
}
