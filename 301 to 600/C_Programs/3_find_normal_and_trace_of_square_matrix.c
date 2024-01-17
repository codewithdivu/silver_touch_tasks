#include <stdio.h>

int main()
{
    int n;
    printf("Enter the order of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &matrix[i][j]);

    int normal = 0, trace = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            normal += matrix[i][j] * matrix[i][j];
            if (i == j)
                trace += matrix[i][j];
        }
    }

    printf("Normal = %d\n", normal);
    printf("Trace = %d\n", trace);

    return 0;
}
