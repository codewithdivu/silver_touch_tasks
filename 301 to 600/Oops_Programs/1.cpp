#include <iostream>
#include <vector>

using namespace std;

class Component
{
public:
    virtual void operation() const = 0;
};

class Leaf : public Component
{
public:
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
    void add(Component *component)
    {
        components.push_back(component);
    }

    void operation() const override
    {
        cout << "Composite operation\n";
        for (auto component : components)
        {
            component->operation();
        }
    }
};

int main()
{
    Leaf leaf1, leaf2;
    Composite composite;

    composite.add(&leaf1);
    composite.add(&leaf2);

    composite.operation();

    return 0;
}
