#include <iostream>
#include <string>
using namespace std;

class Memento {
private:
    string state;

public:
    Memento(const string& s) : state(s) {}

    const string& getState() const {
        return state;
    }
};

class Originator {
private:
    string state;

public:
    void setState(const string& s) {
        state = s;
    }

    Memento createMemento() const {
        return Memento(state);
    }

    void restoreMemento(const Memento& memento) {
        state = memento.getState();
    }

    void printState() const {
        cout << "Current State: " << state << endl;
    }
};

int main() {
    Originator originator;

    originator.setState("State 1");
    originator.printState();

    Memento memento = originator.createMemento();

    originator.setState("State 2");
    originator.printState();

    originator.restoreMemento(memento);
    originator.printState();

    return 0;
}
