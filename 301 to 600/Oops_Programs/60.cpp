#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Block class representing a block in the blockchain
class Block {
public:
    int index;
    string data;
    string previousHash;
    string hash;

    Block(int idx, const string& d, const string& prevHash)
        : index(idx), data(d), previousHash(prevHash) {
        // Simplified hash calculation for demonstration purposes
        hash = calculateHash();
    }

    string calculateHash() const {
        // Simplified hash calculation using index, data, and previous hash
        return to_string(index) + data + previousHash;
    }
};

// Blockchain class representing the chain of blocks
class Blockchain {
private:
    vector<Block> blocks;

public:
    void addBlock(const Block& block) {
        blocks.push_back(block);
    }

    vector<Block> getBlocks() const {
        return blocks;
    }

    // Additional functionalities for validation, consensus, etc.
};

int main() {
    // Create a blockchain
    Blockchain blockchain;

    // Create and add blocks to the blockchain
    Block genesisBlock(0, "Genesis Block", "0");
    Block block1(1, "Transaction Data 1", genesisBlock.hash);
    Block block2(2, "Transaction Data 2", block1.hash);

    // Add blocks to the blockchain
    blockchain.addBlock(genesisBlock);
    blockchain.addBlock(block1);
    blockchain.addBlock(block2);

    // Display the contents of the blockchain
    for (const auto& block : blockchain.getBlocks()) {
        cout << "Block #" << block.index << endl;
        cout << "Data: " << block.data << endl;
        cout << "Hash: " << block.hash << endl;
        cout << "Previous Hash: " << block.previousHash << endl;
        cout << "---------------------" << endl;
    }

    return 0;
}