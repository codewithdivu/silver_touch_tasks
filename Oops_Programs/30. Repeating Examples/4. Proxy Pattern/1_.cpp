#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Resource
{
public:
    virtual void accessResource() = 0;
};

class RealResource : public Resource
{
public:
    void accessResource() override
    {
        cout << "Accessing the costly resource." << endl;
    }
};

class ResourceProxy : public Resource
{
private:
    RealResource *realResource;
    string accessKey;
    bool checkAccess() const
    {
        return accessKey == "divubhai";
    }

public:
    ResourceProxy(const string &key) : accessKey(key), realResource(nullptr) {}

    void accessResource() override
    {
        if (checkAccess())
        {
            if (realResource == nullptr)
            {
                realResource = new RealResource();
            }
            realResource->accessResource();
        }
        else
        {
            cout << "Access denied. Invalid access key." << endl;
        }
    }

    ~ResourceProxy()
    {
        delete realResource;
    }
};

int main()
{
    ResourceProxy proxy("divubhai");

    return 0;
}
