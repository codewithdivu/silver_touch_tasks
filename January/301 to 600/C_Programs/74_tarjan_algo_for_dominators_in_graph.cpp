#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TarjanDominators
{
private:
    int n;
    vector<vector<int>> graph;
    vector<int> dom;
    vector<int> idom;
    vector<int> semi;
    vector<int> ancestor;
    vector<int> label;
    vector<vector<int>> bucket;

    int currentLabel;

    void dfs(int v, vector<bool> &visited)
    {
        visited[v] = true;
        for (int u : graph[v])
        {
            if (!visited[u])
            {
                dfs(u, visited);
            }
        }
        label[currentLabel] = v;
        currentLabel--;
    }

    int find(int v)
    {
        if (ancestor[v] == v)
        {
            return v;
        }
        else
        {
            int root = find(ancestor[v]);
            ancestor[v] = root;
            return root;
        }
    }

    void unionSets(int u, int v)
    {
        ancestor[v] = u;
    }

    bool dominates(int u, int v)
    {
        return find(v) == find(u);
    }

    int semiDominator(int v)
    {
        return label[semi[v]];
    }

    void constructDominatorTree()
    {
        for (int i = 1; i < n; ++i)
        {
            int u = label[i];
            int s = semi[u];
            while (s > semi[ancestor[u]])
            {
                if (s < label[idom[u]])
                {
                    idom[u] = s;
                }
                u = ancestor[u];
            }
        }

        for (int i = 1; i < n; ++i)
        {
            int u = label[i];
            if (idom[u] != semiDominator(u))
            {
                idom[u] = idom[idom[u]];
            }
        }
    }

public:
    TarjanDominators(int nodes) : n(nodes)
    {
        graph.resize(n);
        dom.resize(n, -1);
        idom.resize(n, -1);
        semi.resize(n);
        ancestor.resize(n);
        label.resize(n);
        bucket.resize(n);
        currentLabel = n - 1;
    }

    void addEdge(int from, int to)
    {
        graph[from].push_back(to);
    }

    void computeDominators(int startNode)
    {
        vector<bool> visited(n, false);
        dfs(startNode, visited);

        for (int i = 0; i < n; ++i)
        {
            semi[i] = ancestor[i] = i;
            bucket[i].clear();
        }

        for (int i = n - 1; i > 0; --i)
        {
            int w = label[i];
            for (int v : graph[w])
            {
                if (v != w)
                {
                    int u = semi[v] < semi[w] ? v : w;
                    semi[w] = min(semi[w], semiDominator(u));
                }
            }
            bucket[semi[w]].push_back(w);
            for (int v : bucket[semi[w]])
            {
                int u = semiDominator(v);
                dom[v] = (semi[u] < semi[v]) ? u : semi[v];
            }
            bucket[semi[w]].clear();
            unionSets(ancestor[w], w);
        }

        constructDominatorTree();
    }

    int getDominator(int node)
    {
        return dom[node];
    }

    int getImmediateDominator(int node)
    {
        return idom[node];
    }
};

int main()
{

    int nodes = 7;
    TarjanDominators dominators(nodes);

    dominators.addEdge(0, 1);
    dominators.addEdge(1, 2);
    dominators.addEdge(2, 3);
    dominators.addEdge(3, 4);
    dominators.addEdge(3, 5);
    dominators.addEdge(4, 6);
    dominators.addEdge(5, 6);

    dominators.computeDominators(0);

    cout << "Dominator tree:\n";
    for (int i = 0; i < nodes; ++i)
    {
        cout << "Node " << i << ": Dominator = " << dominators.getDominator(i)
             << ", Immediate Dominator = " << dominators.getImmediateDominator(i) << endl;
    }

    return 0;
}
