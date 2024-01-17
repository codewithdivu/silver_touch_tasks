#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Target
{
public:
    virtual void request() const = 0;
    virtual ~Target() {}
};

class LegacyRectangle
{
public:
    void draw()
    {
        cout << "drawing...LegacyRectangle" << endl;
    }
};

class RectangleAdapter : public Target
{
private:
    LegacyRectangle *legacyRectangle;

public:
    void request() const override
    {
        legacyRectangle->draw();
    }
};

int main()
{
    RectangleAdapter adaptedRectangle;
    return 0;
}