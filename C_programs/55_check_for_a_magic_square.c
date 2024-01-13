/*
The magic square is a square matrix, whose order is odd and where the sum of the elements
for each row or each column or each diagonal is same.
*/

#include <stdio.h>

int main()
{
    int rows, cols;
    printf("enter the rows and columns\n");
    scanf("%d %d", &rows, &cols);
    if (rows != cols)
    {
        printf("please enter same rows and cols");
        return;
    }

    printf("enter the matrix\n");
    int matrix[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int diagonal = 0;
    int arr[rows + cols];
    int counter = 0;

    for (int i = 0; i < rows; i++)
    {
        int ro = 0, co = 0;
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                diagonal += matrix[i][j];
                ro += matrix[i][j];
                co += matrix[j][i];
            }
            else
            {
                ro += matrix[i][j];
                co += matrix[j][i];
            }
        }

        arr[counter] = ro;
        counter++;
        arr[counter] = co;
        counter++;
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    int flag = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != diagonal)
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
    {
        printf("matrix is not Magic Square");
    }
    else
    {
        printf("matrix is Magic Square and sum of each rows, cols and diagonal is %d\n ", diagonal);
    }

    return 0;
}