#include <stdio.h>

int main()
{
    char str[100];
    printf("enter a string for counting the vowels and consonants");
    gets(str);

    int vowels = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowels++;
        }
    }
    int consonants = strlen(str) - vowels;

    printf("Total vowels is %d ", vowels);
    printf("Total consonants is %d ", consonants);

    return 0;
}