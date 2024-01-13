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

    int sub[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sub[i][j] = first[i][j] - second[i][j];
        }
    }

    printf("substraction of both matrix is below \n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", sub[i][j]);
        }
        printf("\n");
    }

    return 0;
}