#include <iostream>

using namespace std;

class LCG
{
public:
    LCG(int seed = 1, int a = 1664525, int c = 1013904223, int m = 2147483648)
        : seed(seed), a(a), c(c), m(m) {}

    int next()
    {
        seed = (a * seed + c) % m;
        return seed;
    }

private:
    int seed;
    int a;
    int c;
    int m;
};

int main()
{
    LCG lcg; 

    for (int i = 0; i < 10; i++)
    {
        int random_number = lcg.next();
        cout << random_number << " ";
    }

    cout << endl;
    return 0;
}
