#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BillingStrategy
{
public:
    virtual double calculateBill(double amount) const = 0;
    virtual ~BillingStrategy() = default;
};

class NormalBilling : public BillingStrategy
{
public:
    double calculateBill(double amount) const override
    {
        return amount;
    }
};

class DiscountBilling : public BillingStrategy
{
public:
    double calculateBill(double amount) const override
    {
        return amount - (0.1 * amount);
    }
};

class BillingSystem
{
private:
    BillingStrategy *billingStrategy;

public:
    BillingSystem(BillingStrategy *strategy) : billingStrategy(strategy) {}

    void setBillingStrategy(BillingStrategy *strategy)
    {
        billingStrategy = strategy;
    }

    double calculateBill(double amount) const
    {
        return billingStrategy->calculateBill(amount);
    }
};
int main()
{
    BillingStrategy *normalBilling = new NormalBilling();
    BillingStrategy *discountBilling = new DiscountBilling();

    BillingSystem billingSystem(normalBilling);

    double amount = 100.0;
    cout << "Normal Billing - Bill Amount: $" << billingSystem.calculateBill(amount) << endl;

    billingSystem.setBillingStrategy(discountBilling);

    cout << "Discount Billing - Bill Amount: $" << billingSystem.calculateBill(amount) << endl;

    return 0;
}
