#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
    virtual void printType() const {
        cout << "Type: " << typeid(*this).name() << endl;
    }
};

class Derived : public Base {};

int main() {
    Base base;
    Derived derived;

    base.printType();
    derived.printType();
    
    Base* derivedPtr = &base;
    if (derivedPtr) {
        cout << "Base class pointer is actually a Derived class\n";
    } else {
        cout << "Base class pointer is not a Derived class\n";
    }
    return 0;
}
