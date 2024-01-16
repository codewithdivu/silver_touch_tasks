#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Color
{
public:
    virtual void fill() const = 0;
    virtual ~Color() {}
};

class RedColor : public Color
{
public:
    void fill() const override
    {
        cout << "Filling the Red color" << endl;
    }
};
class BlueColor : public Color
{
public:
    void fill() const override
    {
        cout << "Filling the Blue color" << endl;
    }
};

class Shape
{
protected:
    Color *color;

public:
    Shape(Color *color) : color(color) {}

    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    Circle(Color *color) : Shape(color) {}

    void draw() const override
    {
        cout << "Drawing Circle ";
        color->fill();
    }
};
int main()
{
    Color *red = new RedColor();
    Color *blue = new BlueColor();

    Shape *redCircle = new Circle(red);

    redCircle->draw();

    return 0;
}