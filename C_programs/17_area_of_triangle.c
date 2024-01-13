#include <stdio.h>

int main()
{
    double base, height;
    printf("enter a base for your triangle");
    scanf("%lf", &base);
    printf("enter a height for your triangle");
    scanf("%lf", &height);
    double area = (base * height) / 2;
    printf("Area of triangle is %.2lf", area);
    return 0;
}