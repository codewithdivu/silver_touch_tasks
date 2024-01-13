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

    return 0;
}