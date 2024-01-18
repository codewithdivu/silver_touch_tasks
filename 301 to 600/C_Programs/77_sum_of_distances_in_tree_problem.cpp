#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        vector<int> result(N, 0);
        vector<int> count(N, 1);
        vector<vector<int>> graph(N, vector<int>());

        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, graph, count, result);
        dfs2(0, -1, graph, count, result, N);

        return result;
    }

private:
    void dfs(int node, int parent, const vector<vector<int>> &graph, vector<int> &count, vector<int> &result)
    {
        for (int neighbor : graph[node])
        {
            if (neighbor != parent)
            {
                dfs(neighbor, node, graph, count, result);
                count[node] += count[neighbor];
                result[node] += result[neighbor] + count[neighbor];
            }
        }
    }

    void dfs2(int node, int parent, const vector<vector<int>> &graph, const vector<int> &count, vector<int> &result, int N)
    {
        for (int neighbor : graph[node])
        {
            if (neighbor != parent)
            {
                result[neighbor] = result[node] - count[neighbor] + (N - count[neighbor]);
                dfs2(neighbor, node, graph, count, result, N);
            }
        }
    }
};

int main()
{

    int N = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};

    Solution solution;
    vector<int> result = solution.sumOfDistancesInTree(N, edges);

    cout << "Sum of Distances for each node:\n";
    for (int i = 0; i < N; ++i)
    {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
