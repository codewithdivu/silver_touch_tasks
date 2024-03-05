#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Component
{
public:
    virtual void add(Component *component) = 0;
    virtual void remove(Component *component) = 0;
    virtual void operation() const = 0;
    virtual ~Component() {}
};

class Leaf : public Component
{
public:
    void add(Component *component) override
    {
        cout << "Cannot add to a leaf.\n";
    }

    void remove(Component *component) override
    {
        cout << "Cannot remove from a leaf.\n";
    }

    void operation() const override
    {
        cout << "Leaf operation\n";
    }
};

class Composite : public Component
{
private:
    vector<Component *> components;

public:
    void add(Component *component) override
    {
        components.push_back(component);
    }

    void remove(Component *component) override
    {
        // components.erase(remove(components.begin(), components.end(), component), components.end());
        components.pop_back();
    }

    void operation() const override
    {
        cout << "Composite operation\n";
        for (const auto &component : components)
        {
            component->operation();
        }
    }
};

int main()
{
    Leaf leaf1, leaf2, leaf3;

    Composite composite;
    composite.add(&leaf1);
    composite.add(&leaf2);

    leaf1.operation();
    leaf2.operation();
    composite.operation();

    composite.add(&leaf3);
    composite.operation();

    composite.remove(&leaf2);
    composite.operation();

    return 0;
}
