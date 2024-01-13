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

    int mul[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                mul[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    printf("Multiplication of both matrix is below \n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", mul[i][j]);
        }
        printf("\n");
    }

    return 0;
}