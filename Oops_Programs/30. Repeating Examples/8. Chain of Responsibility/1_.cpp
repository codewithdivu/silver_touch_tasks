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

    return 0;
}
