#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    virtual void visitElementA(ConcreteElementA *elementA) = 0;
    virtual void visitElementB(ConcreteElementB *elementB) = 0;
};

class Element
{
public:
    virtual void accept(Visitor *visitor) = 0;
};

class ConcreteElementA : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visitElementA(this);
    }

    void operationA()
    {
        cout << "ConcreteElementA operation A" << endl;
    }
};

class ConcreteElementB : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visitElementB(this);
    }

    void operationB()
    {
        cout << "ConcreteElementB operation B" << endl;
    }
};

class ConcreteVisitor : public Visitor
{
public:
    void visitElementA(ConcreteElementA *elementA) override
    {
        elementA->operationA();
    }

    void visitElementB(ConcreteElementB *elementB) override
    {
        elementB->operationB();
    }
};

int main()
{
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ConcreteVisitor visitor;

    elementA.accept(&visitor);
    elementB.accept(&visitor);

    return 0;
}
