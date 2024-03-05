#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrafficLightState;

class TrafficLight
{
private:
    TrafficLightState *currentState;

public:
    TrafficLight();
    ~TrafficLight();

    void setState(TrafficLightState *newState);
    void performAction();

    void simulateTraffic();
};

class TrafficLightState
{
public:
    virtual void performAction(TrafficLight *context) = 0;
    virtual ~TrafficLightState() = default;
};

class RedState : public TrafficLightState
{
public:
    void performAction(TrafficLight *context) override;
};

class YellowState : public TrafficLightState
{
public:
    void performAction(TrafficLight *context) override;
};

class GreenState : public TrafficLightState
{
public:
    void performAction(TrafficLight *context) override;
};

TrafficLight::TrafficLight() : currentState(nullptr)
{
    setState(new RedState());
}

TrafficLight::~TrafficLight()
{
    delete currentState;
}

void TrafficLight::setState(TrafficLightState *newState)
{
    if (currentState != nullptr)
    {
        delete currentState;
    }
    currentState = newState;
}

void TrafficLight::performAction()
{
    if (currentState != nullptr)
    {
        currentState->performAction(this);
    }
}

void TrafficLight::simulateTraffic()
{
    for (int i = 0; i < 5; ++i)
    {
        performAction();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void RedState::performAction(TrafficLight *context)
{
    cout << "Traffic Light is RED. Stop!" << endl;
}

void YellowState::performAction(TrafficLight *context)
{
    cout << "Traffic Light is YELLOW. Prepare to stop." << endl;
}

void GreenState::performAction(TrafficLight *context)
{
    cout << "Traffic Light is GREEN. Go!" << endl;
}

int main()
{
    TrafficLight trafficLight;

    trafficLight.simulateTraffic();

    return 0;
}
