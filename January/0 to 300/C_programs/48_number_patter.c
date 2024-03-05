#include <stdio.h>

int main()
{
    int rows;
    printf("enter the rows \n");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d", i + 1);
        }
        printf("\n");
    }

    return 0;
}