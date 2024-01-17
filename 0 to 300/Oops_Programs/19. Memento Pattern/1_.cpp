#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Memento
{
private:
    string state;

public:
    Memento(string state) : state(state){};

    string getState()
    {
        return this->state;
    }
};

class Originator
{
private:
    string state;

public:
    void setState(string str)
    {
        this->state = str;
    }
    Memento createMemento()
    {
        return Memento(state);
    }
    void restoreFromMemento(Memento &m)
    {
        state = m.getState();
    }

    void printState() const
    {
        cout << "Current State: " << state << endl;
    }
};

int main()
{

    return 0;
}