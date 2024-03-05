#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Component
{
public:
    virtual void display() const = 0;
    virtual ~Component() {}
};

class ConcreteComponent : public Component
{
public:
    void display() const override
    {
        cout << "Displaying ConcreteComponent\n";
    }
};

int main()
{
    Component *component = new ConcreteComponent();
    component->display();
    return 0;
}
