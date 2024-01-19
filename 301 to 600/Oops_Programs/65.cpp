#include <iostream>
#include <vector>
using namespace std;

// Base class representing a shape
class Shape {
public:
    virtual void draw() const = 0;
};

// Derived classes for specific shapes: Circle, Rectangle, Triangle
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Rectangle." << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Triangle." << endl;
    }
};

// Drawing class managing a collection of shapes
class Drawing {
private:
    vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void drawAll() const {
        cout << "Drawing all shapes:" << endl;
        for (const auto& shape : shapes) {
            shape->draw();
        }
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    Drawing drawing;
    drawing.addShape(&circle);
    drawing.addShape(&rectangle);
    drawing.addShape(&triangle);

    drawing.drawAll();

    return 0;
}
