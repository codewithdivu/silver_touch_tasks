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

int main()
{

    return 0;
}