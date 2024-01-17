#include <iostream>
using namespace std;

class Shape
{
public:
    int calculateArea()
    {
        return 0;
    }
};

class Rectangle : public Shape
{
public:
    int calculateArea(int length, int width)
    {
        return length * width;
    }
};
class Circle : public Shape
{
public:
    int calculateArea(int radius)
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Rectangle r;
    int rectangleArea = r.calculateArea(10, 10);
    cout << "area of rectangle is " << rectangleArea << endl;

    Circle c;
    int circleArea = c.calculateArea(5);
    cout << "area of circle is " << circleArea << endl;

    return 0;
}