#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(char *str)
{
    int len = strlen(str);
    int i = 0, j = len - 1;

    while (i < j)
    {
        while (i < j && !isalnum(str[i]))
            i++;
        while (i < j && !isalnum(str[j]))
            j--;

        if (tolower(str[i]) != tolower(str[j]))
            return 0;

        i++;
        j--;
    }

    return 1;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
