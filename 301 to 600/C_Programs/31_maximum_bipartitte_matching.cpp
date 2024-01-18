#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class BipartiteGraph
{
private:
    int leftSetSize;
    int rightSetSize;
    vector<vector<int>> adjList;

public:
    BipartiteGraph(int leftSize, int rightSize) : leftSetSize(leftSize), rightSetSize(rightSize)
    {
        adjList.resize(leftSize);
    }

    void addEdge(int leftVertex, int rightVertex)
    {
        adjList[leftVertex].push_back(rightVertex);
    }

    int hopcroftKarp()
    {
        vector<int> leftMatching(leftSetSize, -1);
        vector<int> rightMatching(rightSetSize, -1);
        vector<int> distance(leftSetSize);

        int matchingCount = 0;

        while (bfs(leftMatching, rightMatching, distance))
        {
            for (int leftVertex = 0; leftVertex < leftSetSize; ++leftVertex)
            {
                if (leftMatching[leftVertex] == -1 && dfs(leftVertex, leftMatching, rightMatching, distance))
                {
                    matchingCount++;
                }
            }
        }

        return matchingCount;
    }

private:
    bool bfs(const vector<int> &leftMatching, const vector<int> &rightMatching, vector<int> &distance)
    {
        queue<int> q;

        for (int leftVertex = 0; leftVertex < leftSetSize; ++leftVertex)
        {
            if (leftMatching[leftVertex] == -1)
            {
                distance[leftVertex] = 0;
                q.push(leftVertex);
            }
            else
            {
                distance[leftVertex] = INT_MAX;
            }
        }

        distance[INT_MAX - 1] = INT_MAX;

        while (!q.empty())
        {
            int leftVertex = q.front();
            q.pop();

            if (distance[leftVertex] < distance[INT_MAX - 1])
            {
                for (int rightVertex : adjList[leftVertex])
                {
                    if (distance[rightMatching[rightVertex]] == INT_MAX)
                    {
                        distance[rightMatching[rightVertex]] = distance[leftVertex] + 1;
                        q.push(rightMatching[rightVertex]);
                    }
                }
            }
        }

        return (distance[INT_MAX - 1] != INT_MAX);
    }

    bool dfs(int leftVertex, vector<int> &leftMatching, vector<int> &rightMatching, vector<int> &distance)
    {
        if (leftVertex != -1)
        {
            for (int rightVertex : adjList[leftVertex])
            {
                if (distance[rightMatching[rightVertex]] == distance[leftVertex] + 1 &&
                    dfs(rightMatching[rightVertex], leftMatching, rightMatching, distance))
                {
                    leftMatching[leftVertex] = rightVertex;
                    rightMatching[rightVertex] = leftVertex;
                    return true;
                }
            }

            distance[leftVertex] = INT_MAX;
            return false;
        }

        return true;
    }
};

int main()
{

    BipartiteGraph graph(4, 4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(2, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 2);
    graph.addEdge(0, 3);
    graph.addEdge(3, 0);

    int maxMatching = graph.hopcroftKarp();

    cout << "Maximum Bipartite Matching: " << maxMatching << endl;

    return 0;
}
