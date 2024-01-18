#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class HungarianAlgorithm
{
private:
    int numVertices;
    vector<vector<int>> costMatrix;
    vector<int> labelX, labelY, matchX, matchY;
    vector<bool> visitedX, visitedY;

public:
    HungarianAlgorithm(int n) : numVertices(n), costMatrix(n, vector<int>(n, 0)),
                                labelX(n, 0), labelY(n, 0), matchX(n, -1), matchY(n, -1),
                                visitedX(n, false), visitedY(n, false) {}

    void addEdge(int x, int y, int cost)
    {
        costMatrix[x][y] = cost;
    }

    int hungarian()
    {
        labelX.assign(numVertices, 0);
        labelY.assign(numVertices, 0);
        matchX.assign(numVertices, -1);
        matchY.assign(numVertices, -1);

        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = 0; j < numVertices; ++j)
            {
                labelX[i] = max(labelX[i], costMatrix[i][j]);
            }
        }

        for (int i = 0; i < numVertices; ++i)
        {
            while (true)
            {
                visitedX.assign(numVertices, false);
                visitedY.assign(numVertices, false);

                if (augmentingPath(i))
                {
                    break;
                }

                int delta = INF;
                for (int j = 0; j < numVertices; ++j)
                {
                    if (visitedX[j])
                    {
                        for (int k = 0; k < numVertices; ++k)
                        {
                            if (!visitedY[k])
                            {
                                delta = min(delta, labelX[j] + labelY[k] - costMatrix[j][k]);
                            }
                        }
                    }
                }

                for (int j = 0; j < numVertices; ++j)
                {
                    if (visitedX[j])
                    {
                        labelX[j] -= delta;
                    }
                    if (visitedY[j])
                    {
                        labelY[j] += delta;
                    }
                }
            }
        }

        int maxMatching = 0;
        for (int i = 0; i < numVertices; ++i)
        {
            if (matchX[i] != -1)
            {
                maxMatching += costMatrix[i][matchX[i]];
            }
        }

        return maxMatching;
    }

private:
    bool augmentingPath(int u)
    {
        visitedX[u] = true;

        for (int v = 0; v < numVertices; ++v)
        {
            if (!visitedY[v] && labelX[u] + labelY[v] == costMatrix[u][v])
            {
                visitedY[v] = true;

                if (matchY[v] == -1 || augmentingPath(matchY[v]))
                {
                    matchX[u] = v;
                    matchY[v] = u;
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    int numVertices;
    cout << "Enter the number of vertices in the bipartite graph: ";
    cin >> numVertices;

    HungarianAlgorithm hungarian(numVertices);

    int numEdges;
    cout << "Enter the number of edges in the bipartite graph: ";
    cin >> numEdges;

    cout << "Enter the edges and their costs (u, v, cost):\n";
    for (int i = 0; i < numEdges; ++i)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        hungarian.addEdge(u, v, cost);
    }

    int maxMatching = hungarian.hungarian();

    cout << "Maximum Bipartite Matching Cost: " << maxMatching << endl;

    return 0;
}
