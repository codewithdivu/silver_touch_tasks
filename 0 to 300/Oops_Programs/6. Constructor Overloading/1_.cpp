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

    return 0;
}