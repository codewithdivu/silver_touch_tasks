#include <stdio.h>

int main()
{

    printf("enter first matrix\n");
    int first[3][3];
    int second[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &first[i][j]);
        }
    }

    printf("enter second matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &second[i][j]);
        }
    }

    int sum[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum[i][j] = first[i][j] + second[i][j];
        }
    }

    printf("Sum of both matrix is below \n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}