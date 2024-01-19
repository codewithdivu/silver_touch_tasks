#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class TransactionalMemorySystem {
private:
    vector<function<void()>> transactions;

public:
    void beginTransaction() {}
    void commitTransaction() {
        
        for (const auto& action : transactions) {
            action();
        }
        transactions.clear();
    }

    void rollbackTransaction() {
        
        transactions.clear();
    }

    template <typename T>
    void atomicOperation(T& variable, const T& newValue) {
        
        transactions.emplace_back([&variable, newValue]() {
            variable = newValue;
        });
    }
};

int main() {
    int sharedVariable = 0;

    TransactionalMemorySystem tms;
    tms.beginTransaction();

    tms.atomicOperation(sharedVariable, 42);

    tms.commitTransaction();

    cout << "Shared Variable after transaction: " << sharedVariable << endl;

    return 0;
}
