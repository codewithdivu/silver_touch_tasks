#include <iostream>
#include <vector>
#include <mutex>
using namespace std;

class Observer
{
public:
    virtual void update(int data) = 0;
};

class Subject
{
private:
    std::vector<Observer *> observers;
    std::mutex mutex;

public:
    void addObserver(Observer *observer)
    {
        std::lock_guard<std::mutex> lock(mutex);
        observers.push_back(observer);
    }

    void notifyObservers(int data)
    {
        std::lock_guard<std::mutex> lock(mutex);
        for (Observer *observer : observers)
        {
            observer->update(data);
        }
    }
};

class ConcreteObserver : public Observer
{
public:
    void update(int data) override
    {
        std::cout << "Received update with data: " << data << std::endl;
    }
};

int main()
{
    Subject subject;
    ConcreteObserver observer1, observer2;

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.notifyObservers(42);

    return 0;
}
