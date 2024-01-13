#include <iostream>

class Drawable
{
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Circle : public Drawable
{
public:
    void draw() const override
    {
        std::cout << "Drawing a circle\n";
    }
};

class Square : public Drawable
{
public:
    void draw() const override
    {
        std::cout << "Drawing a square\n";
    }
};

int main()
{
    Circle circle;
    Square square;

    circle.draw();
    square.draw();

    return 0;
}
