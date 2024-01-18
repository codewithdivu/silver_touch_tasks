#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


long long modPow(long long a, long long b, long long m)
{
    long long result = 1;
    a = a % m;

    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % m;
        }

        b = b >> 1;
        a = (a * a) % m;
    }

    return result;
}


bool millerRabinTest(long long n, int k)
{
    if (n <= 1 || n == 4)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }

    
    long long d = n - 1;
    while (d % 2 == 0)
    {
        d /= 2;
    }

    
    for (int i = 0; i < k; ++i)
    {
        
        long long a = 2 + rand() % (n - 3);

        
        long long x = modPow(a, d, n);

        if (x == 1 || x == n - 1)
        {
            continue;
        }

        
        while (d != n - 1)
        {
            x = (x * x) % n;
            d *= 2;

            if (x == 1)
            {
                return false; 
            }
            if (x == n - 1)
            {
                break; 
            }
        }

        if (x != n - 1)
        {
            return false; 
        }
    }

    return true; 
}

int main()
{
    long long number;
    int k; 

    cout << "Enter a number to test for primality: ";
    cin >> number;

    cout << "Enter the number of iterations (k) for the Miller-Rabin test: ";
    cin >> k;

    if (millerRabinTest(number, k))
    {
        cout << number << " is likely a prime number.\n";
    }
    else
    {
        cout << number << " is a composite number.\n";
    }

    return 0;
}
