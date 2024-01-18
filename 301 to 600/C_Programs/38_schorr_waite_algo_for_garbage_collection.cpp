#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> neighbors;

    Node(int val) : data(val) {}

    void addNeighbor(Node *neighbor)
    {
        neighbors.push_back(neighbor);
    }
};

void schorrWaite(Node *root)
{
    stack<Node *> nodeStack;
    Node *current = root;

    while (current != nullptr || !nodeStack.empty())
    {
        if (current != nullptr)
        {

            cout << "Marking node: " << current->data << endl;

            if (!current->neighbors.empty())
            {
                nodeStack.push(current->neighbors.back());
                current->neighbors.pop_back();
            }

            current = current->neighbors.empty() ? nullptr : current->neighbors.back();
        }
        else
        {

            current = nodeStack.top();
            nodeStack.pop();
        }
    }
}

int main()
{

    Node *root = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    root->addNeighbor(node2);
    root->addNeighbor(node3);
    node2->addNeighbor(node4);

    schorrWaite(root);

    delete root;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
