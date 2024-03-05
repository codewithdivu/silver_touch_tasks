#include <iostream>
using namespace std;

class Component {
public:
    virtual void operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    void operation() const override {
        cout << "Concrete Component\n";
    }
};

class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* comp) : component(comp) {}

    void operation() const override {
        component->operation();
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* comp) : Decorator(comp) {}

    void operation() const override {
        Decorator::operation();
        cout << "Decorator A\n";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* comp) : Decorator(comp) {}

    void operation() const override {
        Decorator::operation();
        cout << "Decorator B\n";
    }
};

int main() {
    ConcreteComponent component;
    ConcreteDecoratorA decoratorA(&component);
    ConcreteDecoratorB decoratorB(&decoratorA);

    decoratorB.operation();

    return 0;
}
