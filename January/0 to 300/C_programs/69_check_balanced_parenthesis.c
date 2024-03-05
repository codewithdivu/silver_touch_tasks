#include <stdio.h>
#include <string.h>

int main()
{
    int stack[100];
    int top = -1;

    char str[100];
    printf("please enter the string\n");
    gets(str);
    int len = strlen(str);

    int flag = 1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack[++top] = str[i];
        }
        else if (str[i] == ')')
        {
            if (stack[top] == '(')
            {
                top--;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        else if (str[i] == '}')
        {
            if (stack[top] == '{')
            {
                top--;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        else if (str[i] == ']')
        {
            if (stack[top] == '[')
            {
                top--;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }

    if (flag == 0 || top >= 0)
    {
        printf("expression is not-balanced");
    }
    else
    {
        printf("expression is balanced");
    }
    return 0;
}