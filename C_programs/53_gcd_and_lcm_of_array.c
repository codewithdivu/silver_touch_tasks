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
    int arr[10] = {2, 4, 6, 8};

    int gcdAnswer = arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < size; i++)
    {
        gcdAnswer = gcd(arr[i], gcdAnswer);
        if (gcdAnswer == 1)
        {
            printf("GCD of all the elements of Array is %d ", 1);
            break;
        }
    }
    printf("GCD of all the elements of Array is %d\n", gcdAnswer);

    int lcmAnswer = arr[0];
    for (int i = 1; i < size; i++)
    {
        lcmAnswer = (arr[i] * lcmAnswer) / gcd(arr[i], lcmAnswer);
    }
    printf("LCM of all the elements of Array is %d ", lcmAnswer);

    return 0;
}