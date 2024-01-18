
#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    int V;  
    vector<list<int>> adj; 

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void eulerianCircuitUtil(int u, vector<int>& circuit) {
        for (int v : adj[u]) {
            if (v != -1 && isValidEdge(u, v)) {
                circuit.push_back(v);
                removeEdge(u, v);
                eulerianCircuitUtil(v, circuit);
            }
        }
    }

    void eulerianCircuit() {
        int startVertex = 0;  

        
        vector<int> circuit;
        eulerianCircuitUtil(startVertex, circuit);

        cout << "Eulerian Circuit 1: ";
        for (int vertex : circuit) {
            cout << vertex << " ";
        }
        cout << endl;

       
        int circuitCount = 2;
        while (hasEdges()) {
            circuit.clear();

          
            eulerianCircuitUtil(startVertex, circuit);

            cout << "Eulerian Circuit " << circuitCount << ": ";
            for (int vertex : circuit) {
                cout << vertex << " ";
            }
            cout << endl;

            circuitCount++;
        }
    }

private:
    bool isValidEdge(int u, int v) {
        return !adj[u].empty();
    }

    void removeEdge(int u, int v) {
        auto it = find(adj[u].begin(), adj[u].end(), v);
        if (it != adj[u].end()) {
            adj[u].erase(it);
        }

        it = find(adj[v].begin(), adj[v].end(), u);
        if (it != adj[v].end()) {
            adj[v].erase(it);
        }
    }

    bool hasEdges() {
        for (int i = 0; i < V; ++i) {
            if (!adj[i].empty()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.eulerianCircuit();

    return 0;
}
