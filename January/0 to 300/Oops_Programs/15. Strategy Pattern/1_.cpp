#include <iostream>
using namespace std;

class PaymentStrategy
{
public:
    virtual void pay(double amount) const = 0;
    virtual ~PaymentStrategy() = default;
};

int main()
{

    return 0;
}