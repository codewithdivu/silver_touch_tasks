#include <iostream>
#include <vector>

using namespace std;

class GraphConnectivity {
private:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void union_sets(int x, int y) {
        x = find(x);
        y = find(y);
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }

public:
    GraphConnectivity(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    void add_edge(int x, int y) {
        union_sets(x, y);
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    void remove_edge(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) return;
        if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        } else {
            parent[x_root] = y_root;
            if (rank[x_root] == rank[y_root]) rank[y_root]++;
        }
    }
};

int main() {
    int n = 7;
    GraphConnectivity g(n);

    int q = 11;
    for (int i = 0; i < q; i++) {
        int operation, x, y;
        cin >> operation >> x >> y;
        if (operation == 1) {
            g.remove_edge(x, y);
        } else {
            if (g.connected(x, y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}