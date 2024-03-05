#include <stdio.h>

int fact(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    return num * fact(num - 1);
}

int main()
{
    int row;
    printf("enter a rows\n");
    scanf("%d", &row);

    for (int i = 0; i < row; i++)
    {
        for (int space = 0; space <= row - i; space++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", fact(i) / (fact(i - j) * fact(j)));
        }
        printf("\n");
    }

    return 0;
}