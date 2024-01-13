#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    void display()
    {
        cout << "name is " << this->name << endl;
        cout << "age is " << this->age << endl;
    }
};

int main()
{
    Person divyesh;
    divyesh.name = "Divyesh";
    divyesh.age = 20;

    divyesh.display();
    return 0;
}