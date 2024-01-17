#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RenderingEngine
{
public:
    virtual void render() const = 0;
    virtual ~RenderingEngine() = default;
};

class OpenGLRenderer : public RenderingEngine
{
public:
    void render() const override
    {
        cout << "Rendering with OpenGL" << endl;
    }
};

class DirectXRenderer : public RenderingEngine
{
public:
    void render() const override
    {
        cout << "Rendering with DirectX" << endl;
    }
};

class Shape
{
protected:
    RenderingEngine *renderer;

public:
    Shape(RenderingEngine *renderer) : renderer(renderer) {}

    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
    Circle(RenderingEngine *renderer) : Shape(renderer) {}

    void draw() const override
    {
        cout << "Drawing Circle ";
        renderer->render();
    }
};

class Square : public Shape
{
public:
    Square(RenderingEngine *renderer) : Shape(renderer) {}

    void draw() const override
    {
        cout << "Drawing Square ";
        renderer->render();
    }
};

int main()
{

    return 0;
}
