#include <stdio.h>

int main()
{
    int num;
    printf("enter a number which you want to reverse it");
    scanf("%d", &num);

    int reverse_num = 0;

    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        reverse_num = reverse_num * 10 + digit;
    }

    printf("reversed number is %d", reverse_num);

    return 0;
}