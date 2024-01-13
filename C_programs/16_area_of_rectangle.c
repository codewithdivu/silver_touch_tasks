#include <stdio.h>

int main()
{
    double length, width;
    printf("enter a length for your rectangle");
    scanf("%lf", &length);
    printf("enter a width for your rectangle");
    scanf("%lf", &width);
    double area = length * width;
    printf("Area of rectangle is %.2lf", area);
    return 0;
}