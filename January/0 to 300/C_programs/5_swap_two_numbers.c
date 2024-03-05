#include <stdio.h>

int main()
{
    int num1, num2;
    printf("enter 2 number which you want to swap");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("num1 and num2 before the swapping %d %d", num1, num2);
    int temp = num1;
    num1 = num2;
    num2 = temp;
    printf("num1 and num2 after the swapping %d %d", num1, num2);
    return 0;
}