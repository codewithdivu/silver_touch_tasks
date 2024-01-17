#include <stdio.h>
#include <math.h>

void factorization(int num)
{
    while (num % 2 == 0)
    {
        printf("%d ", 2);
        num = num / 2;
    }

    for (int i = 3; i <= sqrt(num); i += 2)
    {
        while (num % i == 0)
        {
            printf("%d ", i);
            num = num / i;
        }
    }
    if (num > 2)
    {
        printf("%d ", num);
    }
}

int main()
{
    int num;
    printf("enter the number for which you want prime factorizations\n");
    scanf("%d", &num);

    factorization(num);

    return 0;
}