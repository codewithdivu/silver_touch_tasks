#include <iostream>
using namespace std;

class StateMachine;

class State {
public:
    virtual ~State() = default;
    virtual void handleEvent(StateMachine& fsm) = 0;
};

class StateA : public State {
public:
    void handleEvent(StateMachine& fsm) override;
};

class StateB : public State {
public:
    void handleEvent(StateMachine& fsm) override;
};

class StateMachine {
public:
    StateMachine() : currentState(nullptr) {}

    void setInitialState(State* initialState) {
        currentState = initialState;
    }

    void initialize() {
        setInitialState(&stateA);
    }

    void triggerEvent() {
        currentState->handleEvent(*this);
    }

    void transitionToStateA() {
        currentState = &stateA;
    }

    void transitionToStateB() {
        currentState = &stateB;
    }

private:
    StateA stateA;
    StateB stateB;
    State* currentState;
};

void StateA::handleEvent(StateMachine& fsm) {
    cout << "Handling event in StateA. Transitioning to StateB." << endl;
    fsm.transitionToStateB();
}

void StateB::handleEvent(StateMachine& fsm) {
    cout << "Handling event in StateB. Transitioning to StateA." << endl;
    fsm.transitionToStateA();
}

int main() {
    StateMachine fsm;
    fsm.initialize();

    for (int i = 0; i < 3; ++i) {
        cout << "Triggering event " << i + 1 << endl;
        fsm.triggerEvent();
    }

    return 0;
}