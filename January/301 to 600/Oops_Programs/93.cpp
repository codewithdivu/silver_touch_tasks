#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Transaction {
private:
    string type;
    double amount;
    string date;

public:
    Transaction(const string& transType, double transAmount, const string& transDate)
        : type(transType), amount(transAmount), date(transDate) {}

    const string& getType() const {
        return type;
    }

    double getAmount() const {
        return amount;
    }

    const string& getDate() const {
        return date;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactionHistory;

public:
    Account(int accNumber) : accountNumber(accNumber), balance(0.0) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back(Transaction("Deposit", amount, "Current Date"));
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionHistory.push_back(Transaction("Withdrawal", amount, "Current Date"));
        } else {
            cout << "Insufficient funds!\n";
        }
    }

    void viewTransactionHistory() const {
        cout << "Transaction History for Account " << accountNumber << ":\n";
        cout << "--------------------------------------------\n";
        for (const Transaction& transaction : transactionHistory) {
            cout << "Type: " << transaction.getType() << "\n";
            cout << "Amount: $" << transaction.getAmount() << "\n";
            cout << "Date: " << transaction.getDate() << "\n";
            cout << "--------------------------------------------\n";
        }
    }
};

class Customer {
private:
    string name;
    vector<Account> accounts;

public:
    Customer(const string& customerName) : name(customerName) {}

    const string& getName() const {
        return name;
    }

    void openAccount(int accountNumber) {
        accounts.push_back(Account(accountNumber));
    }

    void transferMoney(int fromAccount, int toAccount, double amount) {
        for (Account& account : accounts) {
            if (account.getAccountNumber() == fromAccount) {
                account.withdraw(amount);
            } else if (account.getAccountNumber() == toAccount) {
                account.deposit(amount);
            }
        }
    }

    void checkAccountBalance(int accountNumber) const {
        for (const Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Account Balance for Account " << accountNumber << ": $" << account.getBalance() << "\n";
                return;
            }
        }
        cout << "Account not found!\n";
    }

    void viewTransactionHistory(int accountNumber) const {
        for (const Account& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.viewTransactionHistory();
                return;
            }
        }
        cout << "Account not found!\n";
    }
};

int main() {
    using namespace std;

    Customer customer("John Doe");
    customer.openAccount(12345);
    customer.openAccount(67890);

    customer.transferMoney(12345, 67890, 100.0);

    customer.checkAccountBalance(12345);
    customer.checkAccountBalance(67890);

    customer.viewTransactionHistory(12345);
    customer.viewTransactionHistory(67890);

    return 0;
}
