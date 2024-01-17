#include <stdio.h>
#include <string.h>

int main()
{
    char first[100], second[100];
    printf("enter 2 string for concatenation");
    gets(first);
    gets(second);
    strcat(first, second);
    printf("concanate string is ");
    puts(first);
    return 0;
}