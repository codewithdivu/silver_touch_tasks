#include <iostream>
#include <vector>
using namespace std;

class DistributedNode {
public:
    int nodeId;

    DistributedNode(int id) : nodeId(id) {}

    void executeTransaction(const string& transaction) const {
        // Simulate the execution of a transaction on the distributed node
        cout << "Node " << nodeId << " executes transaction: " << transaction << endl;
    }
};

class DistributedTransactionSystem {
private:
    vector<DistributedNode> nodes;

public:
    void addNode(const DistributedNode& node) {
        nodes.push_back(node);
    }

    void executeDistributedTransaction(const string& transaction) const {
        // Simulate distributing the transaction to all nodes
        for (const auto& node : nodes) {
            node.executeTransaction(transaction);
        }
    }
};

int main() {
    DistributedNode node1(1);
    DistributedNode node2(2);

    DistributedTransactionSystem transactionSystem;
    transactionSystem.addNode(node1);
    transactionSystem.addNode(node2);

    transactionSystem.executeDistributedTransaction("Transfer $100 from account A to account B");

    return 0;
}
