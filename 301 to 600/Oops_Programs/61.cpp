#include <iostream>
using namespace std;

class BankAccount {
protected:
    double balance;

public:
    BankAccount() : balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    double checkBalance() const {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(double rate) : interestRate(rate) {}

    void applyInterest() {
        balance += balance * interestRate;
        cout << "Interest applied. New balance: $" << balance << endl;
    }
};

int main() {
    SavingsAccount savingsAccount(0.05);

    savingsAccount.deposit(1000.0);
    savingsAccount.applyInterest();
    savingsAccount.withdraw(200.0);

    return 0;
}
