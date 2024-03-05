#include <iostream>
#include <vector>
using namespace std;

class DynamicGraph
{
private:
    struct Node
    {
        int parent;
        int rank;
        int size;

        Node(int parent = -1, int rank = 0) : parent(parent), rank(rank) {}
    };

    vector<Node> nodes;

    int find(int x)
    {
        if (nodes[x].parent != x)
        {
            nodes[x].parent = find(nodes[x].parent);
        }
        return nodes[x].parent;
    }

    void link(int x, int y)
    {
        if (nodes[x].rank > nodes[y].rank)
        {
            nodes[y].parent = x;
        }
        else
        {
            nodes[x].parent = y;
            if (nodes[x].rank == nodes[y].rank)
            {
                nodes[y].rank++;
            }
        }
    }

public:
    DynamicGraph(int n)
    {
        nodes.resize(n);
        for (int i = 0; i < n; i++)
        {
            nodes[i] = Node(i);
        }
    }

    void connect(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y)
        {
            link(root_x, root_y);
        }
    }

    bool is_connected(int x, int y)
    {
        return find(x) == find(y);
    }

    void disconnect(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y)
        {

            int smaller_root = (nodes[root_x].size < nodes[root_y].size) ? root_x : root_y;
            int larger_root = (smaller_root == root_x) ? root_y : root_x;
            int new_parent = find(larger_root);
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i].parent == smaller_root)
                {
                    nodes[i].parent = new_parent;
                }
            }
        }
    }
};

int main()
{
    DynamicGraph g(10);
    g.connect(0, 1);
    g.connect(1, 2);
    g.connect(3, 4);
    g.connect(5, 6);
    g.connect(7, 8);

    cout << "Is 0 connected to 2? " << (g.is_connected(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 1 connected to 3? " << (g.is_connected(1, 3) ? "Yes" : "No") << endl;

    g.disconnect(0, 1);
    cout << "Is 0 connected to 2 after disconnecting 0 from 1? " << (g.is_connected(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 1 connected to 3 after disconnecting 0 from 1? " << (g.is_connected(1, 3) ? "Yes" : "No") << endl;

    return 0;
}