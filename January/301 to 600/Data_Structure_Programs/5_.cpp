#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class UnionFind
{
public:
    unordered_map<int, int> parent;

    int find(int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            return x;
        }

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
            parent[rootY] = rootX;
        }
    }
};

bool isSatisfiable(vector<vector<int>> &equations)
{
    UnionFind uf;

    for (const auto &eq : equations)
    {
        if (eq[1] == '=')
            uf.unionSets(eq[0], eq[3]);
    }

    for (const auto &eq : equations)
    {
        if (eq[1] == '!' && uf.find(eq[0]) == uf.find(eq[3]))
            return false;
    }

    return true;
}

int main()
{

    vector<vector<int>> equations1 = {{1, '=', 2}, {3, '=', 4}, {2, '=', 3}};
    cout << "Satisfiable: " << (isSatisfiable(equations1) ? "true" : "false") << endl;

    vector<vector<int>> equations2 = {{1, '=', 2}, {2, '!', 3}, {3, '=', 4}};
    cout << "Satisfiable: " << (isSatisfiable(equations2) ? "true" : "false") << endl;

    return 0;
}