#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class BlossomAlgorithm {
private:
    int n;
    vector<vector<int>> graph;
    vector<int> match, parent, base, blossom, label, slack;
    queue<int> q;
    vector<bool> inQueue;

public:
    BlossomAlgorithm(int vertices) : n(vertices), graph(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int u, int v) {
        graph[u][v] = graph[v][u] = 1;
    }

    int findMaxCardinalityMatching() {
        match.assign(n, -1);
        parent.assign(n, -1);
        base.assign(n, -1);
        blossom.assign(n, -1);
        label.assign(n, -1);
        slack.assign(n, 0);
        inQueue.assign(n, false);

        for (int i = 0; i < n; ++i) {
            if (match[i] == -1) {
                augment(i);
            }
        }

        int maxCardinality = count(match.begin(), match.end(), -1) / 2; 
        return maxCardinality;
    }

private:
    int findCommonAncestor(int u, int v) {
        vector<bool> inPath(n, false);

        while (true) {
            u = base[u];
            inPath[u] = true;

            if (match[u] == -1)
                break;

            u = parent[match[u]];
        }

        while (true) {
            v = base[v];
            if (inPath[v])
                break;
            v = parent[match[v]];
        }

        return v;
    }

    void updateSlack(int u, int blossomBase, int delta) {
        while (base[u] != blossomBase) {
            int v = parent[match[u]];
            blossom[base[u]] = blossom[base[v]] = 1;
            delta = slack[v];
            u = v;
        }
    }

    void augment(int startNode) {
        q = queue<int>();
        q.push(startNode);
        inQueue[startNode] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; ++v) {
                if (graph[u][v] && base[u] != base[v]) {
                    if (label[v] == -1) {
                        label[v] = u;
                        if (match[v] == -1) {
                            augmentPath(v);
                            return;
                        }

                        q.push(match[v]);
                        inQueue[match[v]] = true;
                    } else {
                        int blossomBase = findCommonAncestor(u, v);
                        contractBlossom(u, v, blossomBase);
                    }
                }
            }
        }
    }

    void augmentPath(int v) {
        while (v != -1) {
            int pv = label[v];
            int ppv = match[pv];
            match[v] = pv;
            match[pv] = v;
            v = ppv;
        }
    }

    void contractBlossom(int u, int v, int blossomBase) {
        vector<int> path;
        while (base[u] != blossomBase) {
            path.push_back(u);
            blossom[base[u]] = blossom[base[parent[match[u]]]] = 1;
            u = parent[match[u]];
        }

        while (base[v] != blossomBase) {
            path.push_back(v);
            blossom[base[v]] = blossom[base[parent[match[v]]]] = 1;
            v = parent[match[v]];
        }

        int ancestor = findCommonAncestor(u, v);

        resetBlossomLabels(blossomBase);
        resetBlossomLabels(ancestor);

        label[ancestor] = -1;
        updateSlack(u, blossomBase, 0);
        updateSlack(v, blossomBase, 0);

        for (int i = 0; i < path.size(); ++i) {
            int node = path[i];
            if (!inQueue[node])
                q.push(node);
            inQueue[node] = true;
            slack[node] = slack[ancestor];
        }
    }

    void resetBlossomLabels(int blossomBase) {
        for (int v = 0; v < n; ++v) {
            if (blossom[base[v]]) {
                base[v] = blossomBase;
                if (!inQueue[v])
                    q.push(v);
                inQueue[v] = true;
            }
        }
    }
};

int main() {
    
    BlossomAlgorithm blossom(6);
    blossom.addEdge(0, 1);
    blossom.addEdge(1, 2);
    blossom.addEdge(2, 3);
    blossom.addEdge(3, 4);
    blossom.addEdge(4, 5);
    blossom.addEdge(5, 0);

    int maxCardinality = blossom.findMaxCardinalityMatching();
    cout << "Maximum Cardinality Matching: " << maxCardinality << endl;

    return 0;
}
