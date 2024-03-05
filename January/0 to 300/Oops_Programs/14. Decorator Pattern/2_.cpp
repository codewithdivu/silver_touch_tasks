#include <iostream>
using namespace std;

class Coffee
{
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffee() = default;
};

class Espresso : public Coffee
{
public:
    string getDescription() const override
    {
        return "Espresso";
    }
    double cost() const override
    {
        return 1.0;
    }
};

// decorator class

class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeeDecorator(Coffee *coffe) : coffee(coffee) {}

    string getDescription() const override
    {
        return coffee->getDescription();
    }

    double cost() const override
    {
        return coffee->cost();
    }
};

class MilkDecorator : public CoffeeDecorator
{
public:
    MilkDecorator(Coffee *coffee) : CoffeeDecorator(coffee) {}

    string getDescription() const override
    {
        return coffee->getDescription() + ", milk";
    }

    double cost() const override
    {
        return coffee->cost() + 3.0;
    }
};
class SugarDecorator : public CoffeeDecorator
{
public:
    SugarDecorator(Coffee *coffee) : CoffeeDecorator(coffee) {}

    string getDescription() const override
    {
        return coffee->getDescription() + ", sugar";
    }

    double cost() const override
    {
        return coffee->cost() + 6.0;
    }
};

int main()
{
    Coffee *myEspresso = new Espresso();
    cout << "Description: " << myEspresso->getDescription() << ", Cost: $" << myEspresso->cost() << endl;

    Coffee *milkEspresso = new MilkDecorator(myEspresso);
    cout << "Description: " << milkEspresso->getDescription() << ", Cost: $" << milkEspresso->cost() << endl;

    Coffee *sweetMilkEspresso = new SugarDecorator(milkEspresso);
    cout << "Description: " << sweetMilkEspresso->getDescription() << ", Cost: $" << sweetMilkEspresso->cost() << endl;

    return 0;
}