#include <iostream>
#include <cstdlib>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    int balance;

public:
    BankAccount(int amount)
    {
        this->balance = amount;
        this->accountNumber = rand();
    }

    int getAccountNumber()
    {
        return this->accountNumber;
    }
    int getAccountBalance(int accountNumber)
    {
        if (accountNumber == this->accountNumber)
        {
            return this->accountNumber;
        }
    }

    void deposit(int amount, int accountNumber)
    {
        if (accountNumber == this->accountNumber)
        {
            this->balance = this->balance + amount;
        }
    }
    void withdraw(int amount, int accountNumber)
    {
        if (accountNumber == this->accountNumber)
        {
            if (amount < this->balance)
            {
                this->balance = this->balance - amount;
            }
        }
    }
};

int main()
{
    BankAccount dk(2000);
    int myAccountNumber = dk.getAccountNumber();
    dk.deposit(3000, myAccountNumber);
    dk.withdraw(1000, myAccountNumber);
    dk.getAccountBalance(myAccountNumber);
    return 0;
}