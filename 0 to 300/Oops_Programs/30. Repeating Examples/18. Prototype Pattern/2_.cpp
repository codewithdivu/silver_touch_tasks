#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    virtual Animal *clone() const = 0;
    virtual void makeSound() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    Animal *clone() const override
    {
        return new Dog(*this);
    }

    void makeSound() const override
    {
        cout << "Dog barks!" << endl;
    }
};

class Cat : public Animal
{
public:
    Animal *clone() const override
    {
        return new Cat(*this);
    }

    void makeSound() const override
    {
        cout << "Cat meows!" << endl;
    }
};

class AnimalPrototypeFactory
{
private:
    unordered_map<string, Animal *> prototypes;

public:
    AnimalPrototypeFactory()
    {
        prototypes["Dog"] = new Dog();
        prototypes["Cat"] = new Cat();
    }

    Animal *createAnimal(const string &type) const
    {
        auto it = prototypes.find(type);
        if (it != prototypes.end())
        {
            return it->second->clone();
        }
        return nullptr;
    }

    ~AnimalPrototypeFactory()
    {
        for (auto &pair : prototypes)
        {
            delete pair.second;
        }
    }
};

int main()
{
    AnimalPrototypeFactory prototypeFactory;

    Animal *dog = prototypeFactory.createAnimal("Dog");
    Animal *cat = prototypeFactory.createAnimal("Cat");

    if (dog)
    {
        dog->makeSound();
        delete dog;
    }

    if (cat)
    {
        cat->makeSound();
        delete cat;
    }

    return 0;
}
