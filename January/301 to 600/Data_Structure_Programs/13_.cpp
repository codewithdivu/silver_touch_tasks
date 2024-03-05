#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int parent;
    int weight;
};

void dfs(int node, vector<vector<int>> &tree, vector<Node> &nodes, vector<bool> &visited)
{
    visited[node] = true;

    for (int neighbor : tree[node])
    {
        if (!visited[neighbor])
        {
            nodes[neighbor].parent = node;
            nodes[neighbor].weight = abs(nodes[node].weight - nodes[neighbor].weight);
            dfs(neighbor, tree, nodes, visited);
        }
    }
}

int findRoot(int node, vector<Node> &nodes)
{
    if (nodes[node].parent != node)
    {
        nodes[node].parent = findRoot(nodes[node].parent, nodes);
    }
    return nodes[node].parent;
}

int main()
{

    int N1 = 7;
    vector<int> weights1 = {1, 2, 6, 4, 2, 0, 3};
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {4, 6}, {6, 7}};

    vector<Node> nodes1(N1 + 1);
    vector<vector<int>> tree1(N1 + 1);

    for (int i = 1; i <= N1; ++i)
    {
        nodes1[i].parent = i;
        nodes1[i].weight = weights1[i - 1];
    }

    for (const auto &edge : edges1)
    {
        tree1[edge[0]].push_back(edge[1]);
        tree1[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited1(N1 + 1, false);
    dfs(1, tree1, nodes1, visited1);

    int N2 = 6;
    vector<int> weights2 = {2, 4, 0, 2, 2, 6};
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 6}};

    vector<Node> nodes2(N2 + 1);
    vector<vector<int>> tree2(N2 + 1);

    for (int i = 1; i <= N2; ++i)
    {
        nodes2[i].parent = i;
        nodes2[i].weight = weights2[i - 1];
    }

    for (const auto &edge : edges2)
    {
        tree2[edge[0]].push_back(edge[1]);
        tree2[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited2(N2 + 1, false);
    dfs(1, tree2, nodes2, visited2);

    cout << "Roots for Example 1: ";
    for (int i = 1; i <= N1; ++i)
    {
        cout << findRoot(i, nodes1) << " ";
    }
    cout << endl;

    cout << "Roots for Example 2: ";
    for (int i = 1; i <= N2; ++i)
    {
        cout << findRoot(i, nodes2) << " ";
    }
    cout << endl;

    return 0;
}
