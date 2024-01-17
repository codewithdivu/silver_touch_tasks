#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("enter the string for reversing\n");
    gets(str);
    int start = 0;
    int end = strlen(str) - 1;
    printf("string before the reverse -> ");
    puts(str);
    while (start <= end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    printf("string after the reverse -> ");
    puts(str);

    return 0;
}