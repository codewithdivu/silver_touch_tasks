#include <stdio.h>

int main()
{
    double principal, time, rate;
    printf("Enter initial principal balance");
    scanf("%lf", &principal);
    printf("Enter time in years");
    scanf("%lf", &time);
    printf("Enter annual interest rate");
    scanf("%lf", &rate);

    double interest = principal*(1 + (time * rate));
    printf("Simple interest is %.2lf", interest);

    return 0;
}