#include <stdio.h>

int main()
{
    int row;
    printf("enter the rows\n");
    scanf("%d", &row);
    int counter = 1;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", counter++);
        }
        printf("\n");
    }

    return 0;
}