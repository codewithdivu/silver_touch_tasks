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

class RealImage : public Image
{
private:
    string filename;
    void loadImageFromDisk()
    {
        cout << "Loading image from disk: " << filename << endl;
    }

public:
    RealImage(string filename) : filename(filename)
    {
        loadImageFromDisk();
    }

    void display()
    {
        cout << "Displaying the real image " << this->filename << " " << endl;
    }
};

class ProxyImage : public Image
{
private:
    RealImage *realImage;
    string filename;

public:
    ProxyImage(const string &file) : realImage(nullptr), filename(file) {}

    ~ProxyImage()
    {
        delete realImage;
    }

    void display() const override
    {

        cout << "ProxyImage: Checking access before displaying." << endl;
        realImage->display();
    }
};

int main()
{
    Image *image = new ProxyImage("example.jpg");

    image->display();

    image->display();

    delete image;
    return 0;
}