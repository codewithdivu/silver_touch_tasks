#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Logger
{
public:
    virtual void logMessage(const string &request) = 0;
    virtual ~Logger() {}
};

class ConcreteLogger1 : public Logger
{
public:
    void logMessage(const string &request) override
    {
        if (request == "Logger1")
        {
            cout << "ConcreteLogger1 is Logging the message.\n";
        }
        else if (getNextHandler() != nullptr)
        {
            getNextHandler()->logMessage(request);
        }
        else
        {
            cout << "No Logger can logging the message.\n";
        }
    }

    virtual Logger *getNextHandler() const
    {
        return nullptr;
    }
};

class ConcreteLogger2 : public Logger
{
public:
    void logMessage(const string &request) override
    {
        if (request == "Logger2")
        {
            cout << "ConcreteLogger2 is logging the message.\n";
        }
        else if (getNextHandler() != nullptr)
        {
            getNextHandler()->logMessage(request);
        }
        else
        {
            cout << "No Logger can logging the message.\n";
        }
    }

    virtual Logger *getNextHandler() const
    {
        return nullptr;
    }
};

int main()
{
    Logger *logger1 = new ConcreteLogger1();
    Logger *logger2 = new ConcreteLogger2();

    logger1->logMessage("Logger1");
    logger1->logMessage("Logger2");

    delete logger1;
    delete logger2;

    return 0;
}
