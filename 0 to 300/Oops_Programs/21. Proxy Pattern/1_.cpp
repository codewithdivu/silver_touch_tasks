#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Image
{
public:
    virtual void display() const = 0;
    virtual ~Image() {}
};

class ConcreteImage : public Image
{
public:
    void display() const override
    {
        cout << "displaying the image" << endl;
    }
};

int main()
{
    Image *image = new ConcreteImage();
    image->display();
    return 0;
}