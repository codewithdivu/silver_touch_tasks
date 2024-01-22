#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Block {
public:
    int index;
    string data;
    string previousHash;
    string hash;

    Block(int idx, const string& d, const string& prevHash)
        : index(idx), data(d), previousHash(prevHash) {
        
        hash = calculateHash();
    }

    string calculateHash() const {
        
        return to_string(index) + data + previousHash;
    }
};


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

    
};

int main() {
    
    Blockchain blockchain;

    
    Block genesisBlock(0, "Genesis Block", "0");
    Block block1(1, "Transaction Data 1", genesisBlock.hash);
    Block block2(2, "Transaction Data 2", block1.hash);

    
    blockchain.addBlock(genesisBlock);
    blockchain.addBlock(block1);
    blockchain.addBlock(block2);

    
    for (const auto& block : blockchain.getBlocks()) {
        cout << "Block #" << block.index << endl;
        cout << "Data: " << block.data << endl;
        cout << "Hash: " << block.hash << endl;
        cout << "Previous Hash: " << block.previousHash << endl;
        cout << "---------------------" << endl;
    }

    return 0;
}