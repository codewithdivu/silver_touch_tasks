#include <stdio.h>

int main()
{
    int rows, cols, sum = 0;
    printf("enter the rows and columns\n");
    scanf("%d %d", &rows, &cols);

    printf("enter the matrix\n");
    int matrix[3][3];

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
            if (i == j)
            {
                sum = sum + matrix[i][j];
            }
        }
    }

    printf("Sum of  matrix is %d\n", sum);

    return 0;
}