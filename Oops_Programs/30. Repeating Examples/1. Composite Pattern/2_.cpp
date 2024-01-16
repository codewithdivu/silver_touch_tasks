#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Component
{
public:
    virtual void display() const = 0;
    virtual ~Component() {}
};

class Leaf : public Component
{
private:
    string name;

public:
    Leaf(const string &name) : name(name) {}

    void display() const override
    {
        cout << "Leaf: " << name << "\n";
    }
};

class Composite : public Component
{
private:
    vector<Component *> components;

public:
    void add(Component *component)
    {
        components.push_back(component);
    }

    void display() const override
    {
        cout << "Composite:\n";
        for (const auto &component : components)
        {
            component->display();
        }
    }

    ~Composite()
    {
        for (const auto &component : components)
        {
            delete component;
        }
    }
};

int main()
{
    Component *leaf1 = new Leaf("Leaf 1");
    Component *leaf2 = new Leaf("Leaf 2");
    Component *leaf3 = new Leaf("Leaf 3");

    Composite *composite1 = new Composite();
    composite1->add(leaf1);
    composite1->add(leaf2);

    Composite *composite2 = new Composite();
    composite2->add(composite1);
    composite2->add(leaf3);

    leaf1->display();
    leaf2->display();
    leaf3->display();
    composite1->display();
    composite2->display();

    return 0;
}
