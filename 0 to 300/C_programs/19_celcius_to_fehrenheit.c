/*
    F = C * (9/5) + (32)
    C = (F-32) * (5/9)
*/

#include <stdio.h>

int main()
{
    double celcius;
    printf("enter temperature in celcius");
    scanf("%lf", &celcius);
    double fehrenheit = celcius * (9 / 5) + (32);
    printf("temperature in fehrenheit is %lf", fehrenheit);
    return 0;
}