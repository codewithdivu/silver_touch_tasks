#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Observer
{
public:
    virtual void update(double temperature, double humidity) = 0;
    virtual ~Observer() = default;
};

class Subject
{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

class WeatherStation : public Subject
{
private:
    double temperature;
    double humidity;
    vector<Observer *> observers;

public:
    void setMeasurements(double temperature, double humidity)
    {
        this->temperature = temperature;
        this->humidity = humidity;
        notifyObservers();
    }

    void addObserver(Observer *observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer) override
    {
        observers.pop_back();
    }

    void notifyObservers() override
    {
        for (Observer *observer : observers)
        {
            observer->update(temperature, humidity);
        }
    }
};

int main()
{

    return 0;
}
