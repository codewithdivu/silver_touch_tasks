#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n, r;

    printf("Enter values of n and r: ");
    scanf("%d %d", &n, &r);

    printf("Permutation (nPr) = %d\n", permutation(n, r));
    printf("Combination (nCr) = %d\n", combination(n, r));

    return 0;
}
