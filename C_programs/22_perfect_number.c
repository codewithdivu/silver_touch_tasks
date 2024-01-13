#include <stdio.h>

int main()
{
    int num, rem, sum = 0;
    printf("enter a number to check for perfect number");
    scanf("%d", &num);

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == num)
        printf("Number is Perfect");
    else
        printf("Number is not a perfect");

    return 0;
}