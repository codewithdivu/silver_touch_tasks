#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MobileAlertState
{
public:
    virtual void alert() = 0;
};

class AlertStateContext
{
private:
    MobileAlertState *currentState;

public:
    AlertStateContext(){};

    void setState(MobileAlertState *state)
    {
        currentState = state;
    }

    void alert() { currentState->alert(); }
};

int main()
{
    AlertStateContext stateContext;

    return 0;
}
