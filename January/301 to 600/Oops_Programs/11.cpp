#include <iostream>
using namespace std;

class Handler {
protected:
    Handler* successor;

public:
    Handler() : successor(nullptr) {}

    void setSuccessor(Handler* succ) {
        successor = succ;
    }

    virtual void handleRequest(int request) const = 0;
};

class ConcreteHandlerA : public Handler {
public:
    void handleRequest(int request) const override {
        if (request < 10) {
            cout << "Handler A handles the request: " << request << endl;
        } else if (successor) {
            successor->handleRequest(request);
        }
    }
};

class ConcreteHandlerB : public Handler {
public:
    void handleRequest(int request) const override {
        if (request >= 10 && request < 20) {
            cout << "Handler B handles the request: " << request << endl;
        } else if (successor) {
            successor->handleRequest(request);
        }
    }
};

class ConcreteHandlerC : public Handler {
public:
    void handleRequest(int request) const override {
        if (request >= 20) {
            cout << "Handler C handles the request: " << request << endl;
        } else if (successor) {
            successor->handleRequest(request);
        }
    }
};

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;
    ConcreteHandlerC handlerC;

    handlerA.setSuccessor(&handlerB);
    handlerB.setSuccessor(&handlerC);

    handlerA.handleRequest(5);
    handlerA.handleRequest(15);
    handlerA.handleRequest(25);

    return 0;
}
