#include <iostream>
using namespace std;

class Document
{
public:
    virtual void print() const = 0;
    virtual ~Document() = default;
};

class PDFDocument : public Document
{
public:
    void print() const override
    {
        cout << "Printing a PDF Document\n";
    }
};
class WordDocument : public Document
{
public:
    void print() const override
    {
        cout << "Printing a Word Document\n";
    }
};

int main()
{

    return 0;
}