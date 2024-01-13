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
};

int main()
{

    return 0;
}