#include <stdio.h>

int power(int base, int exponent)
{
    int result = 1;

    while (exponent != 0)
    {
        result *= base;
        --exponent;
    }

    return result;
}

int main()
{
    int base, exponent;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exponent);

    printf("%d^%d = %d\n", base, exponent, power(base, exponent));

    return 0;
}
