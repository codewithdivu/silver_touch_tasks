#include <iostream>
#include <vector>
using namespace std;

class Command
{
public:
    virtual void execute() const = 0;
    virtual ~Command() = default;
};

int main()
{

    return 0;
}