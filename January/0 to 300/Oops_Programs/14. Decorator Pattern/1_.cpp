#include <iostream>
using namespace std;

class Coffe
{
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffe() = default;
};

class espresso : public Coffe
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

int main()
{

    return 0;
}