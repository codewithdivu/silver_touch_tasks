#include <iostream>
using namespace std;

class Animal
{
public:
    void eat()
    {
    }
    void sound()
    {
    }
};

class Dog : public Animal
{
public:
    void eat()
    {
        cout << "Fish eating..." << endl;
    }
    void sound()
    {
        cout << "Barking...." << endl;
    }
};
class Cat : public Animal
{
public:
    void eat()
    {
        cout << "Fish eating..." << endl;
    }
    void sound()
    {
        cout << "Meou..Meou...." << endl;
    }
};

int main()
{

    Dog jimmy;
    jimmy.eat();
    jimmy.sound();

    Cat Timmu;
    Timmu.eat();
    Timmu.sound();

    return 0;
}