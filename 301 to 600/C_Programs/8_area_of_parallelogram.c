#include <stdio.h>

int main()
{
    float base, height;

    printf("Enter base and height of the parallelogram: ");
    scanf("%f %f", &base, &height);

    float area = base * height;

    printf("Area of the parallelogram = %.2f\n", area);

    return 0;
}
