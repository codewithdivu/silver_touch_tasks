#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Prototype
{
public:
    virtual Prototype *clone() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Prototype() {}
};

class ConcretePrototype1 : public Prototype
{
public:
    Prototype *clone() const override
    {
        return new ConcretePrototype1(*this);
    }

    void printInfo() const override
    {
        cout << "ConcretePrototype1\n";
    }
};

class ConcretePrototype2 : public Prototype
{
public:
    Prototype *clone() const override
    {
        return new ConcretePrototype2(*this);
    }

    void printInfo() const override
    {
        cout << "ConcretePrototype2\n";
    }
};

class PrototypeManager
{
private:
    unordered_map<string, Prototype *> prototypes;

public:
    ~PrototypeManager()
    {
        for (const auto &pair : prototypes)
        {
            delete pair.second;
        }
    }

    void addPrototype(const string &key, Prototype *prototype)
    {
        prototypes[key] = prototype;
    }

    Prototype *getPrototype(const string &key) const
    {
        auto it = prototypes.find(key);
        if (it != prototypes.end())
        {
            return it->second->clone();
        }
        return nullptr;
    }
};

int main()
{
    PrototypeManager manager;

    manager.addPrototype("Prototype1", new ConcretePrototype1());
    manager.addPrototype("Prototype2", new ConcretePrototype2());

    Prototype *clonedPrototype1 = manager.getPrototype("Prototype1");
    if (clonedPrototype1)
    {
        clonedPrototype1->printInfo();
        delete clonedPrototype1;
    }

    Prototype *clonedPrototype2 = manager.getPrototype("Prototype2");
    if (clonedPrototype2)
    {
        clonedPrototype2->printInfo();
        delete clonedPrototype2;
    }

    return 0;
}
