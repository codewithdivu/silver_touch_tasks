#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }

    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a == 0 ? b : a;
}

int main()
{
    int num1, num2;
    printf("enter 2 number for which you want LCM\n");
    scanf("%d %d", &num1, &num2);

    int answer = (num1 * num2) / gcd(num1, num2);

    printf("lcm of these number is %d ", answer);
    return 0;
}

/*
gcd(a,b)*lcm(a,b) = a*b;
*/