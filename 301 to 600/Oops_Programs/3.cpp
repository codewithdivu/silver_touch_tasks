
#include <iostream>
using namespace std;

class Implementor {
public:
    virtual void implement() const = 0;
};

class ConcreteImplementorA : public Implementor {
public:
    void implement() const override {
        cout << "Concrete Implementor A\n";
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void implement() const override {
        cout << "Concrete Implementor B\n";
    }
};

class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* imp) : implementor(imp) {}

    virtual void operation() const = 0;
};

class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* imp) : Abstraction(imp) {}

    void operation() const override {
        cout << "Refined Abstraction ";
        implementor->implement();
    }
};

int main() {
    ConcreteImplementorA impA;
    ConcreteImplementorB impB;

    RefinedAbstraction abstractionA(&impA);
    RefinedAbstraction abstractionB(&impB);

    abstractionA.operation();
    abstractionB.operation();

    return 0;
}
