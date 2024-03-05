#include <iostream>
using namespace std;

class Prototype {
public:
    virtual Prototype* clone() const = 0;

    virtual void printInfo() const = 0;
};

class ConcretePrototype : public Prototype {
public:
    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void printInfo() const override {
        cout << "Concrete Prototype\n";
    }
};

int main() {
    ConcretePrototype original;
    Prototype* cloned = original.clone();

    original.printInfo();
    cloned->printInfo();

    delete cloned;

    return 0;
}