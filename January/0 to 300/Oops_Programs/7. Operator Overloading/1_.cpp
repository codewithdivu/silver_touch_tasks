#include <iostream>
using namespace std;

class Complex
{
private:
    int real, image;

public:
    Complex(int real = 0, int image = 0)
    {
        this->real = real;
        this->image = image;
    }

    Complex operator+(Complex const &c)
    {
        Complex res;
        res.real = this->real + c.real;
        res.image = this->image + c.image;
        return res;
    }

    void display()
    {
        cout << "Real is " << this->real << " and Image is " << this->image << endl;
    }
};

int main()
{

    return 0;
}