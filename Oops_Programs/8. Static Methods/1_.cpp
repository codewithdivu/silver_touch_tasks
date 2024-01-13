#include <iostream>
#include <cmath>
using namespace std;

class MathOperations
{
public:
    static void square(int num)
    {
        cout << "square root is " << sqrt(num) << endl;
    }
};

int main()
{
    MathOperations md;
    md.square(16);

    return 0;
}