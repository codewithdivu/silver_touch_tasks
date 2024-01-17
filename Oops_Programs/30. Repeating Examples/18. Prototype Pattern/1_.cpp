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

int main()
{

    return 0;
}
