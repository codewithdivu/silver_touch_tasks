#include <stdio.h>

int get_anagrm(char arr1[], char arr2[])
{
    int num1[20] = {0}, num2[20] = {0}, i = 0;

    while (arr1[i] != '\0')
    {
        num1[arr1[i] - 'a']++;
        printf("%d", arr1[i] - 'a');
        i++;
    }

    i = 0;

    while (arr2[i] != '\0')
    {
        num2[arr2[i] - 'a']++;
        i++;
    }

    for (i = 0; i < 20; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
}

int main()
{
    char arr1[100], arr2[100];
    int count;

    printf(" Enter the first string: \n ");
    scanf(" %s", arr1);

    printf(" Enter the second string: \n ");
    scanf(" %s", arr2);

    count = get_anagrm(arr1, arr2);

    if (count == 1)
    {
        printf(" %s and %s strings are an anagram of each other. \n", arr1, arr2);
    }
    else
    {
        printf(" %s and %s strings are not an anagram of each other. \n", arr1, arr2);
    }

    return 0;
}
