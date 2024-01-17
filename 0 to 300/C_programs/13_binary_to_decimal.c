#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("enter a number which you want decimal format");
    scanf("%d", &num);

    int counter = 1;
    int decimal_number = 0;
    while (num != 0)
    {
        int digit = num % 10;
        decimal_number += counter * digit;
        counter *= 2;
        num = num / 10;
    }
    printf("decimal number is %d", decimal_number);

    return 0;
}