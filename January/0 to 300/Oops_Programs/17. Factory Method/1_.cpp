#include <iostream>
using namespace std;

class Document
{
public:
    virtual void print(const string &msg) const = 0;
    virtual ~Document() = default;
};

int main()
{

    return 0;
}