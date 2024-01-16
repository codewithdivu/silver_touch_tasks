#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
public:
    virtual void drive() const = 0;
};

class Car : public Vehicle
{
public:
    void drive() const override
    {
        cout << "Driving a car." << endl;
    }
};

class Bicycle : public Vehicle
{
public:
    void drive() const override
    {
        cout << "Riding a bicycle." << endl;
    }
};

int main()
{

    return 0;
}
