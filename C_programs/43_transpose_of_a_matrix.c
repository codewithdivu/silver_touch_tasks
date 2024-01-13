#include <stdio.h>

int main()
{

    printf("enter matrix\n");
    int matrix[3][3];
    int transpose[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("Transpose of matrix is below \n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}