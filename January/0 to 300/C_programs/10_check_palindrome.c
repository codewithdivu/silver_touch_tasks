#include <stdio.h>
#include <string.h>

// first approach for checking number is palindrome is to reverse the number and compare it with actuall if it same then number is palindrome

// second approach for checking string is palindrome is below

int main()
{
    char str[100];
    gets(str);

    int start = 0;
    int end = strlen(str) - 1;

    while (start <= end)
    {
        if (str[start] != str[end])
        {
            printf("string is not-Palindrome");
            return;
        }
        start++;
        end--;
    }

    printf("string is Palindrome");

    return 0;
}