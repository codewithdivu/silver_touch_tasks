#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class PersistentUnionFind {
private:
    struct Node {
        int parent;
        int rank;

        Node(int p) : parent(p), rank(0) {}
    };

    vector<unordered_map<int, Node>> snapshots; 
    int currentTime; 

public:
    PersistentUnionFind(int n) : currentTime(0) {
        snapshots.emplace_back(); 
        for (int i = 0; i < n; ++i) {
            snapshots[currentTime][i] = Node(i);
        }
    }

    int find(int time, int x) {
        while (snapshots[time][x].parent != x) {
            x = snapshots[time][x].parent;
        }
        return x;
    }

    void unite(int time, int x, int y) {
        x = find(time, x);
        y = find(time, y);

        if (x != y) {
            if (snapshots[time][x].rank < snapshots[time][y].rank) {
                snapshots[time][x].parent = y;
            } else if (snapshots[time][x].rank > snapshots[time][y].rank) {
                snapshots[time][y].parent = x;
            } else {
                snapshots[time][y].parent = x;
                snapshots[time][x].rank++;
            }
        }
    }

    void snapshot() {
        currentTime++;
        snapshots.push_back(snapshots[currentTime - 1]); 
    }

    int getCurrentTime() const {
        return currentTime;
    }

    void print(int time) {
        cout << "Snapshot " << time << ":\n";
        for (const auto& node : snapshots[time]) {
            cout << "Node " << node.first << ", Parent: " << node.second.parent << ", Rank: " << node.second.rank << "\n";
        }
    }
};

int main() {
    
    PersistentUnionFind puf(5);

    puf.snapshot(); 
    puf.unite(puf.getCurrentTime(), 0, 1);
    puf.unite(puf.getCurrentTime(), 2, 3);

    puf.snapshot(); 
    puf.unite(puf.getCurrentTime(), 1, 3);

    puf.snapshot(); 
    puf.unite(puf.getCurrentTime(), 0, 4);

    puf.print(0);
    puf.print(1);
    puf.print(2);

    return 0;
}
