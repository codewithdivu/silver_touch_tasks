#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Event {
public:
    virtual string apply() const = 0;
};

class State {
private:
    string currentState;

public:
    void applyEvent(const Event& event) {
        currentState = event.apply();
    }

    void printState() const {
        cout << "Current State: " << currentState << endl;
    }
};

class StateChangeEvent : public Event {
private:
    string newState;

public:
    StateChangeEvent(const string& state) : newState(state) {}

    string apply() const override {
        
        
        cout << "Applying State Change Event: " << newState << endl;
        return newState;
    }
};

int main() {
    State state;

    StateChangeEvent event1("State1");
    state.applyEvent(event1);
    state.printState();

    StateChangeEvent event2("State2");
    state.applyEvent(event2);
    state.printState();

    return 0;
}
