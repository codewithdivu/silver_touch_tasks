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
        cout << "Sitting on a modern chair." << endl;
    }
};

class VictorianChair : public Chair
{
public:
    void sit() const override
    {
        cout << "Sitting on a Victorian chair." << endl;
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
        cout << "Relaxing on a modern sofa." << endl;
    }
};

class VictorianSofa : public Sofa
{
public:
    void relax() const override
    {
        cout << "Relaxing on a Victorian sofa." << endl;
    }
};

class FurnitureFactory
{
public:
    virtual Chair *createChair() const = 0;
    virtual Sofa *createSofa() const = 0;
    virtual ~FurnitureFactory() = default;
};

class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() const override
    {
        return new ModernChair();
    }

    Sofa *createSofa() const override
    {
        return new ModernSofa();
    }
};

class VictorianFurnitureFactory : public FurnitureFactory
{
public:
    Chair *createChair() const override
    {
        return new VictorianChair();
    }

    Sofa *createSofa() const override
    {
        return new VictorianSofa();
    }
};

int main()
{
    FurnitureFactory *modernFactory = new ModernFurnitureFactory();
    Chair *modernChair = modernFactory->createChair();
    Sofa *modernSofa = modernFactory->createSofa();

    modernChair->sit();
    modernSofa->relax();

    FurnitureFactory *victorianFactory = new VictorianFurnitureFactory();
    Chair *victorianChair = victorianFactory->createChair();
    Sofa *victorianSofa = victorianFactory->createSofa();

    victorianChair->sit();
    victorianSofa->relax();

    return 0;
}
