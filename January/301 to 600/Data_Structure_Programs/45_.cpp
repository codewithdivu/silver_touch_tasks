#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<list<int>> adjList;

public:
    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool hasEulerianCircuitOrPath();

    void findEulerianCircuitOrPath(int startVertex);
};

bool Graph::hasEulerianCircuitOrPath()
{

    for (int i = 0; i < vertices; ++i)
    {
        if (adjList[i].size() % 2 != 0)
        {
            return false;
        }
    }

    return true;
}

void Graph::findEulerianCircuitOrPath(int startVertex)
{
    if (!hasEulerianCircuitOrPath())
    {
        cout << "The graph does not have an Eulerian circuit or path." << endl;
        return;
    }

    vector<list<int>> adjCopy = adjList;

    list<int> circuit;

    list<int> result;

    circuit.push_back(startVertex);
    int currentVertex = startVertex;

    while (!circuit.empty())
    {
        if (adjCopy[currentVertex].empty())
        {

            result.push_front(currentVertex);

            currentVertex = circuit.back();
            circuit.pop_back();
        }
        else
        {

            int nextVertex = adjCopy[currentVertex].front();
            circuit.push_back(nextVertex);

            adjCopy[currentVertex].pop_front();
            adjCopy[nextVertex].remove(currentVertex);

            currentVertex = nextVertex;
        }
    }

    cout << "Eulerian Circuit or Path: ";
    for (int vertex : result)
    {
        cout << vertex << " ";
    }
    cout << endl;
}

int main()
{

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    g.findEulerianCircuitOrPath(0);

    return 0;
}
