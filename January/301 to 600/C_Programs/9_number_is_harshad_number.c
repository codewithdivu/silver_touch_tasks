#include <stdio.h>

int isHarshad(int num)
{
    int sum = 0, n = num;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return (num % sum == 0);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isHarshad(num))
        printf("%d is a Harshad number.\n", num);
    else
        printf("%d is not a Harshad number.\n", num);

    return 0;
}
