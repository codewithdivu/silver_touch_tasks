#include <iostream>
using namespace std;

class PaymentStrategy
{
public:
    virtual void pay(double amount) const = 0;
    virtual ~PaymentStrategy() = default;
};

class CreditCardPayment : public PaymentStrategy
{
private:
    string cardNumber;
    string cardHolder;
    string expirationDate;
    string cvv;

public:
    CreditCardPayment(const string &number, const string &name, const string &date, const string &cvv) : cardNumber(number), cardHolder(name), expirationDate(date), cvv(cvv) {}

    void pay(double amount) const override
    {
        cout << "Paid $" << amount << " using credit card ending with " << cardNumber.substr(cardNumber.length() - 4) << endl;
    }
};

class PayPalPayment : public PaymentStrategy
{
private:
    string email;

public:
    PayPalPayment(const string &email) : email(email) {}

    void pay(double amount) const override
    {
        cout << "Paid $" << amount << " using PayPal account with email: " << email << endl;
    }
};

int main()
{
    CreditCardPayment creditCard("1234-5678-9012-3456", "Divyesh Mavadiya", "12/23", "123");
    creditCard.pay(50.0);
    PayPalPayment payPal("divu0017@gmail.com");
    payPal.pay(30.0);

    return 0;
}