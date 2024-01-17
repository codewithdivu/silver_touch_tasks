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

class ConcreteFactory1 : public AbstractFactory
{
public:
    ProductA *createProductA() const override
    {
        return new ConcreteProductA1();
    }

    ProductB *createProductB() const override
    {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    ProductA *createProductA() const override
    {
        return new ConcreteProductA2();
    }

    ProductB *createProductB() const override
    {
        return new ConcreteProductB2();
    }
};

int main()
{
    AbstractFactory *factory1 = new ConcreteFactory1();
    ProductA *productA1 = factory1->createProductA();
    ProductB *productB1 = factory1->createProductB();

    productA1->display();
    productB1->display();

    delete productA1;
    delete productB1;
    delete factory1;

    AbstractFactory *factory2 = new ConcreteFactory2();
    ProductA *productA2 = factory2->createProductA();
    ProductB *productB2 = factory2->createProductB();

    productA2->display();
    productB2->display();

    delete productA2;
    delete productB2;
    delete factory2;

    return 0;
}
