#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("enter a number which you want binary format");
    scanf("%d", &num);

    int counter = 0;
    int binary_number = 0;

    while (num != 0)
    {
        int bit = num & 1;
        binary_number = (bit * pow(10, counter)) + binary_number;
        num = num >> 1;
        counter++;
    }

    printf("binary number is %d\n", binary_number);
    return 0;
}