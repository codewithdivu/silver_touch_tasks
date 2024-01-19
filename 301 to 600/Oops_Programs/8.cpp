#include <iostream>
#include <vector>
using namespace std;

class Visitor;

class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override;
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override;
};

class Visitor {
public:
    virtual void visitElementA(ConcreteElementA& elementA) const = 0;
    virtual void visitElementB(ConcreteElementB& elementB) const = 0;
};

class ConcreteVisitor : public Visitor {
public:
    void visitElementA(ConcreteElementA& elementA) const override {
        cout << "Visitor visits Concrete Element A\n";
    }

    void visitElementB(ConcreteElementB& elementB) const override {
        cout << "Visitor visits Concrete Element B\n";
    }
};

void ConcreteElementA::accept(Visitor& visitor) {
    visitor.visitElementA(*this);
}

void ConcreteElementB::accept(Visitor& visitor) {
    visitor.visitElementB(*this);
}

int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;
    ConcreteVisitor visitor;

    elementA.accept(visitor);
    elementB.accept(visitor);

    return 0;
}
