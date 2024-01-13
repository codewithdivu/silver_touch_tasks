/*
    F = C * (9/5) + (32)
    C = (F-32) * (5/9)
*/

#include <stdio.h>

int main()
{
    double fehrenheit;
    printf("enter temperature in fehrenheit");
    scanf("%lf", &fehrenheit);
    double celcius = (fehrenheit - 32) * (5 / 9);
    printf("temperature in celcius is %lf", celcius);
    return 0;
}