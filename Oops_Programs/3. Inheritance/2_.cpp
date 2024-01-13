#include <iostream>
using namespace std;

class Shape
{
public:
    int calculateArea()
    {
        return 0;
    }
    int calculateParemeter()
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

    int calculateParemeter(int a, int b)
    {
        return 2 * a + 2 * b;
    }
};
class Circle : public Shape
{
public:
    int calculateArea(int radius)
    {
        return 3.14 * radius * radius;
    }

    int calculateParemeter(int radius)
    {
        return 2 * 3.14 * radius;
    }
};

int main()
{
    Rectangle r;
    int rectangleArea = r.calculateArea(10, 10);
    int rectanglePerimeter = r.calculateParemeter(10, 10);
    cout << "area of rectangle is " << rectangleArea << " and perimeter is " << rectanglePerimeter << endl;

    Circle c;
    int circleArea = c.calculateArea(5);
    int circlePerimeter = c.calculateParemeter(5);
    cout << "area of circle is " << circleArea << " and perimeter is " << circlePerimeter << endl;

    return 0;
}