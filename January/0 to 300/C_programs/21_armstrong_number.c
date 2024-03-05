#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("enter number which you want to check for armstrong");
    scanf("%d", &num);
    int sum = 0;
    int originalNum = num;

    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        sum = sum + pow(digit, 3);
    }

    if (sum == originalNum)
    {
        printf("number is armstrong");
    }
    else
    {

        printf("number is not armstrong");
    }

    return 0;
}