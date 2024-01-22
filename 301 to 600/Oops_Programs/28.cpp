#include <iostream>
using namespace std;

class SmartContract {
public:
    virtual void execute() const = 0;
};

class TransferContract : public SmartContract {
public:
    void execute() const override {
        cout << "Executing Transfer Contract\n";
        
    }
};

class EscrowContract : public SmartContract {
public:
    void execute() const override {
        cout << "Executing Escrow Contract\n";
        
    }
};

class SmartContractExecutor {
public:
    void executeContract(const SmartContract& contract) const {
        cout << "Smart Contract Executor executing ";
        contract.execute();
    }
};

int main() {
    TransferContract transferContract;
    EscrowContract escrowContract;

    SmartContractExecutor executor;
    executor.executeContract(transferContract);
    executor.executeContract(escrowContract);

    return 0;
}
