#include <stdio.h>
#define PI 3.14

int main()
{
    int radius;
    printf("enter a radius for your circle");
    scanf("%d", &radius);
    double area = PI * radius * radius;
    printf("Area of circle is %.2lf", area);
    return 0;
}