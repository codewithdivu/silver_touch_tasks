#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};

class DynamicConnectivity {
private:
    UnionFind uf;

public:
    DynamicConnectivity(int n) : uf(n) {}

    
    void addEdge(int x, int y) {
        uf.unite(x, y);
    }

    
    void removeEdge(int x, int y) {
        
        
        uf.unite(x, y);
    }

    
    bool isConnected(int x, int y) {
        return uf.find(x) == uf.find(y);
    }
};

int main() {
    
    int numNodes = 5;
    DynamicConnectivity dsu(numNodes);

    dsu.addEdge(0, 1);
    dsu.addEdge(1, 2);

    cout << "Is 0 connected to 2? " << (dsu.isConnected(0, 2) ? "Yes" : "No") << endl;

    dsu.removeEdge(0, 1);

    cout << "Is 0 connected to 2 after removing edge (0, 1)? " << (dsu.isConnected(0, 2) ? "Yes" : "No") << endl;

    return 0;
}
