#include <stdio.h>
#include <math.h>
#define PI 3.14
int main()
{
    float radius;

    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);

    float surfaceArea = 4 * PI * radius * radius;

    printf("Surface area of the sphere = %.2f\n", surfaceArea);

    return 0;
}
