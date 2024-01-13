#include <iostream>

class ProductA
{
public:
    virtual void display() const = 0;
    virtual ~ProductA() = default;
};

class ConcreteProductA1 : public ProductA
{
public:
    void display() const override
    {
        std::cout << "Concrete Product A1\n";
    }
};

class ConcreteProductA2 : public ProductA
{
public:
    void display() const override
    {
        std::cout << "Concrete Product A2\n";
    }
};

class ProductB
{
public:
    virtual void display() const = 0;
    virtual ~ProductB() = default;
};

class ConcreteProductB1 : public ProductB
{
public:
    void display() const override
    {
        std::cout << "Concrete Product B1\n";
    }
};

class ConcreteProductB2 : public ProductB
{
public:
    void display() const override
    {
        std::cout << "Concrete Product B2\n";
    }
};

class AbstractFactory
{
public:
    virtual ProductA *createProductA() const = 0;
    virtual ProductB *createProductB() const = 0;
    virtual ~AbstractFactory() = default;
};

int main()
{

    return 0;
}
