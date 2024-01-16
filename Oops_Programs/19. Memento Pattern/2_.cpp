#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Memento
{
private:
    string state;

public:
    Memento(string state) : state(move(state)) {}

    string getState() const
    {
        return state;
    }
};

class Originator
{
private:
    string state;

public:
    void setState(string str)
    {
        state = move(str);
    }
    Memento createMemento()
    {
        return Memento(state);
    }
    void restoreFromMemento(const Memento &m)
    {
        state = m.getState();
    }

    void printState() const
    {
        cout << "Current State: " << state << endl;
    }
};

class Caretaker
{
private:
    Memento memento;

public:
    Caretaker() : memento("") {}

    void saveState(Originator &originator)
    {
        memento = originator.createMemento();
    }

    void restoreState(Originator &originator)
    {
        originator.restoreFromMemento(memento);
    }
};

int main()
{
    Originator originator;
    Caretaker caretaker;

    // Set initial state
    originator.setState("State 1");
    originator.printState();

    // Save the state
    caretaker.saveState(originator);

    // Change the state
    originator.setState("State 2");
    originator.printState();

    // Restore the previous state
    caretaker.restoreState(originator);
    originator.printState();
    return 0;
}
