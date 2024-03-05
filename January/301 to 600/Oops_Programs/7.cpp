#include <iostream>
using namespace std;

class State {
public:
    virtual void handle() const = 0;
};

class ConcreteStateA : public State {
public:
    void handle() const override {
        cout << "Concrete State A\n";
    }
};

class ConcreteStateB : public State {
public:
    void handle() const override {
        cout << "Concrete State B\n";
    }
};

class Context {
private:
    State* state;

public:
    void setState(State* st) {
        state = st;
    }

    void request() const {
        state->handle();
    }
};

int main() {
    ConcreteStateA stateA;
    ConcreteStateB stateB;

    Context context;
    context.setState(&stateA);
    context.request();

    context.setState(&stateB);
    context.request();

    return 0;
}
