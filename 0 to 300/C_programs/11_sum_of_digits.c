#include <stdio.h>

int main()
{
    int num;
    printf("enter a number");
    scanf("%d", &num);
    int sum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        sum = sum + digit;
    }

    printf("sum of digit is %d", sum);
    return 0;
}