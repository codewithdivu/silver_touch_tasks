#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("enter string for calculating the length");
    gets(str);
    printf("%ld", strlen(str));
    return 0;
}