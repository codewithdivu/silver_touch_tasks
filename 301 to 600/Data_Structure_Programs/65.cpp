#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> tree[MAXN];
int parent[MAXN];
int depth[MAXN];
int chainHead[MAXN];
int chainIndex[MAXN];
int chainSize[MAXN];
int chainPos[MAXN];
int chainCount;

int segmentTree[4 * MAXN];


void hld(int node, int par, int d) {
    depth[node] = d;
    parent[node] = par;
    chainSize[node] = 1;

    for (int i = 0; i < tree[node].size(); ++i) {
        int child = tree[node][i];
        if (child != par) {
            hld(child, node, d + 1);
            chainSize[node] += chainSize[child];
        }
    }
}


void decompose(int node, int par, int head) {
    chainIndex[node] = chainCount;
    chainPos[node] = chainSize[node];
    chainHead[node] = head;

    if (chainPos[node] == 1)
        chainCount++;

    int heavyChild = -1, maxSize = 0;
    for (int i = 0; i < tree[node].size(); ++i) {
        int child = tree[node][i];
        if (child != par && chainSize[child] > maxSize) {
            maxSize = chainSize[child];
            heavyChild = child;
        }
    }

    if (heavyChild != -1)
        decompose(heavyChild, node, head);

    for (int i = 0; i < tree[node].size(); ++i) {
        int child = tree[node][i];
        if (child != par && child != heavyChild)
            decompose(child, node, child);
    }
}


void update(int index, int value, int node, int left, int right) {
    if (left == right) {
        segmentTree[node] = value;
        return;
    }

    int mid = (left + right) / 2;
    if (index <= mid)
        update(index, value, 2 * node, left, mid);
    else
        update(index, value, 2 * node + 1, mid + 1, right);

    segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
}


int query(int u, int v) {
    int result = 0;

    while (chainIndex[u] != chainIndex[v]) {
        if (depth[chainHead[u]] < depth[chainHead[v]])
            swap(u, v);

        int chainStart = chainHead[u];
        int posU = chainPos[u];
        int posStart = chainPos[chainStart];

        result += querySegmentTree(1, 1, chainSize[chainStart], posStart, posU);
        
        u = parent[chainStart];
    }

    if (depth[u] > depth[v])
        swap(u, v);

    int posU = chainPos[u];
    int posV = chainPos[v];

    result += querySegmentTree(1, 1, chainSize[chainHead[u]], posU, posV);

    return result;
}


int querySegmentTree(int node, int left, int right, int queryLeft, int queryRight) {
    if (queryLeft > right || queryRight < left)
        return 0;

    if (queryLeft <= left && right <= queryRight)
        return segmentTree[node];

    int mid = (left + right) / 2;
    return querySegmentTree(2 * node, left, mid, queryLeft, queryRight) +
           querySegmentTree(2 * node + 1, mid + 1, right, queryLeft, queryRight);
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    
    chainCount = 0;
    hld(1, 0, 0);
    decompose(1, 0, 1);

    
    update(chainPos[2], 5, 1, 1, chainSize[chainHead[2]]);

    
    int result = query(3, 5);
    cout << "Sum on the path between nodes 3 and 5: " << result << endl;

    return 0;
}
