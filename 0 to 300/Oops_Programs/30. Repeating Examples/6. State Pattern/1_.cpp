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

int main()
{
    return 0;
}
