#include <iostream>
using namespace std;

class Strategy {
public:
    virtual void execute() const = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        cout << "Strategy A executed\n";
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        cout << "Strategy B executed\n";
    }
};

class Context {
private:
    Strategy* strategy;

public:
    void setStrategy(Strategy* strat) {
        strategy = strat;
    }

    void executeStrategy() const {
        strategy->execute();
    }
};

int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;

    Context context;

    context.setStrategy(&strategyA);
    context.executeStrategy();

    context.setStrategy(&strategyB);
    context.executeStrategy();

    return 0;
}
