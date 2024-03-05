#include <stdio.h>

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int n, k;

    printf("Enter the total number of people (n): ");
    scanf("%d", &n);

    printf("Enter the counting interval (k): ");
    scanf("%d", &k);

    printf("The safe position is: %d\n", josephus(n, k));

    return 0;
}
