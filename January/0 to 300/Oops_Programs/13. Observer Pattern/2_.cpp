#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual void update(const string &message) = 0;
    virtual ~Observer() = default;
};

class ConcreteObserver : public Observer
{
public:
    void update(const string &message) override
    {
        cout << "Received update: " << message << endl;
    }
};

class Subject
{
public:
    virtual void addObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers(const string &message) = 0;
    virtual ~Subject() = default;
};

class ConcreteSubject : public Subject
{
private:
    vector<Observer *> observers;

public:
    void addObserver(Observer *observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer) override
    {
        auto it = remove(observers.begin(), observers.end(), observer);
        observers.erase(it, observers.end());
    }

    void notifyObservers(const string &message) override
    {
        for (Observer *observer : observers)
        {
            observer->update(message);
        }
    }
};

int main()
{
    ConcreteSubject subject;

    ConcreteObserver observer1;
    ConcreteObserver observer2;

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.notifyObservers("State change message");

    subject.removeObserver(&observer1);

    subject.notifyObservers("Another state change message");

    return 0;
}
