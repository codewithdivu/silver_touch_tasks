#include <iostream>
using namespace std;

class Person
{
    string name;
    int age;
    string address;
    string city;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    Person(string name, int age, string address, string city)
    {
        this->name = name;
        this->age = age;
        this->address = address;
        this->city = city;
    }
};

int main()
{
    Person Dk("Divyesh", 20);
    Person Daddu("Dushyant", 26, "navapara area", "Porbandar");
    return 0;
}