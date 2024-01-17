#include <iostream>
using namespace std;

class Engine
{
private:
    int cylinders;
    double displacement;

public:
    Engine(int cylinders, double displacement)
        : cylinders(cylinders), displacement(displacement) {}

    void start()
    {
        cout << "Engine started\n";
    }

    void stop()
    {
        cout << "Engine stopped\n";
    }
};

class Car
{
private:
    string make;
    string model;
    int year;
    Engine engine;

public:
    Car(const string &make, const string &model, int year, int cylinders, double displacement)
        : make(make), model(model), year(year), engine(cylinders, displacement) {}

    void start()
    {
        cout << "Car started..." << endl;
        engine.start();
    }

    void stop()
    {
        cout << "Car stopped" << endl;
        engine.stop();
    }
};

int main()
{
    Car myCar("Toyota", "Camry", 2022, 4, 2.5);

    myCar.start();
    myCar.stop();
    return 0;
}