#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
public:
    virtual void drive() const = 0;
};

class Car : public Vehicle
{
public:
    void drive() const override
    {
        cout << "Driving a car." << endl;
    }
};

class Bicycle : public Vehicle
{
public:
    void drive() const override
    {
        cout << "Riding a bicycle." << endl;
    }
};

class VehicleFactory
{
public:
    virtual Vehicle *createVehicle() const = 0;
};

class CarFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() const override
    {
        return new Car();
    }
};

class BicycleFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() const override
    {
        return new Bicycle();
    }
};

int main()
{
    VehicleFactory *carFactory = new CarFactory();
    Vehicle *car = carFactory->createVehicle();
    car->drive();

    VehicleFactory *bicycleFactory = new BicycleFactory();
    Vehicle *bicycle = bicycleFactory->createVehicle();
    bicycle->drive();

    return 0;
}
