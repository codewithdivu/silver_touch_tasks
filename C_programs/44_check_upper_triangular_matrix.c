/*
UPPER_TRIANGULAR_MATRIX = a matrix is called upper triangular
if all the entries below the diagonal equal to 0
*/

#include <stdio.h>

int main()
{

    int matrix[3][3] = {
        {1, 2, 3}, {0, 6, 4}, {0, 0, 6}};

    int flag = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j < i)
            {
                if (matrix[i][j] != 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
    }

    if (flag == 0)
    {
        printf("matrix is not upper triangular matrix\n");
    }
    else
    {
        printf("matrix is upper triangular matrix\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}