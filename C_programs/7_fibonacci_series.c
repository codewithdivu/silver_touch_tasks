#include <stdio.h>

int main()
{
    int num;
    printf("Enter how many steps you want to print of fibonacci series");
    scanf("%d", &num);

    int t1 = 0, t2 = 1, nextTerm;

    for (int i = 1; i <= num; i++)
    {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}