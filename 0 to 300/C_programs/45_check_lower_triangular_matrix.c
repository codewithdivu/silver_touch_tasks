/*
LOWER_TRIANGULAR_MATRIX = a matrix is called lower triangular
if all the entries above the diagonal equal to 0
*/

#include <stdio.h>

int main()
{

    int matrix[3][3] = {
        {6, 0, 0},
        {4, 6, 0},
        {1, 2, 3},
    };

    int flag = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j > i)
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
        printf("matrix is not lower triangular matrix\n");
    }
    else
    {
        printf("matrix is lower triangular matrix\n");
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