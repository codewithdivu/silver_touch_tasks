#include <stdio.h>

int main()
{
    int rows;
    printf("enter the rows\n");
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++)
    {
        for (int space = 1; space <= rows - i; space++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 1; i < rows; i++)
    {
        for (int space = 1; space <= i; space++)
        {
            printf(" ");
        }
        for (int j = 1; j <= rows - i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}