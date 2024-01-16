#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MobileAlertState
{
public:
    virtual void alert() = 0;
};

class Vibration : public MobileAlertState
{
public:
    void alert() override
    {
        cout << "vibration..." << endl;
    }
};

class Silent : public MobileAlertState
{
public:
    void alert() override
    {
        cout << "silent..." << endl;
    }
};

class AlertStateContext
{
private:
    MobileAlertState *currentState;

public:
    AlertStateContext() { currentState = new Vibration(); }

    void setState(MobileAlertState *state)
    {
        currentState = state;
    }

    void alert() { currentState->alert(); }
};

int main()
{
    AlertStateContext stateContext;
    stateContext.alert();
    stateContext.alert();
    stateContext.setState(new Silent());
    stateContext.alert();
    stateContext.alert();
    stateContext.alert();

    return 0;
}
