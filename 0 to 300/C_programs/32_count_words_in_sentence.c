#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("enter a string for which you want to count words\n");
    gets(str);

    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    printf("total words is %d ", count+1);

    return 0;
}
