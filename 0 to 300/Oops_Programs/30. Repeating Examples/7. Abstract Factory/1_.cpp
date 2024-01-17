#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Chair
{
public:
    virtual void sit() const = 0;
    virtual ~Chair() = default;
};

class ModernChair : public Chair
{
public:
    void sit() const override
    {
        cout << "Sitting on a modern chair.\n";
    }
};

class VictorianChair : public Chair
{
public:
    void sit() const override
    {
        cout << "Sitting on a Victorian chair.\n";
    }
};

class Sofa
{
public:
    virtual void relax() const = 0;
    virtual ~Sofa() = default;
};

class ModernSofa : public Sofa
{
public:
    void relax() const override
    {
        cout << "Relaxing on a modern sofa.\n";
    }
};

class VictorianSofa : public Sofa
{
public:
    void relax() const override
    {
        cout << "Relaxing on a Victorian sofa.\n";
    }
};

class FurnitureFactory
{
public:
    virtual Chair *createChair() const = 0;
    virtual Sofa *createSofa() const = 0;
    virtual ~FurnitureFactory() = default;
};

int main()
{

    return 0;
}
