#include <stdio.h>

float cm = 0, m = 0, km = 0, ft = 0;

void cal(int a, int op)
{
    switch (op)
    {
    case 1:
        cm = a / 1.0;
        m = cm / 100;
        km = m / 1000;
        ft = m * 3.28084;
        break;
    case 2:
        m = a;
        km = m / 1000;
        ft = m * 3.28084;
        cm = m * 100;
        break;
    case 3:
        km = a;
        m = km * 1000;
        ft = m * 3.28084;
        cm = m * 100;
        break;
    case 4:
        ft = a;
        m = ft / 3.28084;
        km = m / 1000;
        cm = m * 100;
        break;
    default:
        break;
    }
    printf("cm: %.2f,m: %.2f,km: %.2f, ft: %.2f", cm, m, km, ft);
    return;
}

int main()
{
    int a, b, op;
    printf("Enter  value: ");
    scanf("%d", &a);
    printf("what is the unit of this value");
    printf("\nselect 1 for  cm\nselect 2 for m \nselect 3 for km \nselect 4 for ft:");
    scanf("%d", &op);
    cal(a, op);
}