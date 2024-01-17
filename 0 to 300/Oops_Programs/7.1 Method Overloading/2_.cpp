#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator cc;
    cout << "sum of two element is : " << cc.add(5, 10) << endl;
    cout << "sum of three element is : " << cc.add(5, 10, 55) << endl;
    return 0;
}