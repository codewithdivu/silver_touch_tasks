#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Handler
{
public:
    virtual void handleRequest(const string &request) = 0;
    virtual ~Handler() {}
};

class ConcreteHandler1 : public Handler
{
public:
    void handleRequest(const string &request) override
    {
        if (request == "Handler1")
        {
            cout << "ConcreteHandler1 is handling the request.\n";
        }
        else if (getNextHandler() != nullptr)
        {
            getNextHandler()->handleRequest(request);
        }
        else
        {
            cout << "No handler can process the request.\n";
        }
    }

    virtual Handler *getNextHandler() const
    {
        return nullptr;
    }
};

class ConcreteHandler2 : public Handler
{
public:
    void handleRequest(const string &request) override
    {
        if (request == "Handler2")
        {
            cout << "ConcreteHandler2 is handling the request.\n";
        }
        else if (getNextHandler() != nullptr)
        {
            getNextHandler()->handleRequest(request);
        }
        else
        {
            cout << "No handler can process the request.\n";
        }
    }

    virtual Handler *getNextHandler() const
    {
        return nullptr;
    }
};

int main()
{
    Handler *handler1 = new ConcreteHandler1();
    Handler *handler2 = new ConcreteHandler2();

    handler1->handleRequest("Handler1");
    handler1->handleRequest("Handler2");

    delete handler1;
    delete handler2;

    return 0;
}
