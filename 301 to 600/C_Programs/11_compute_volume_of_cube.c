#include <stdio.h>

int main() {
    float side;

    printf("Enter the side length of the cube: ");
    scanf("%f", &side);

    float volume = side * side * side;

    printf("Volume of the cube = %.2f\n", volume);

    return 0;
}
