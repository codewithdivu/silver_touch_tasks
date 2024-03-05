#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char operator)
{
    if (operator== '^')
    {
        return 3;
    }
    else if (operator== '/' || operator== '*')
    {
        return 2;
    }
    else if (operator== '+' || operator== '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int stack[100];
    int top = 0;

    char str[100];
    printf("please enter the infix string\n");
    gets(str);

    int answer[100];
    int counter = 0;
    int len = strlen(str);
    int par = 0;

    for (int i = 0; i < len; i++)
    {

        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            answer[counter++] = str[i];
        }
        else if (str[i] == '(')
        {
            stack[++top] = str[i];
            par++;
        }
        else if (str[i] == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                answer[counter++] = stack[top--];
            }
            top--;
            par++;
        }
        else
        {
            while (top >= 0 && precedence(stack[top]) > precedence(str[i]))
            {
                answer[counter++] = stack[top];
                top--;
            }
            stack[++top] = str[i];
        }
    }

    int size = sizeof(answer) / sizeof(4);

    for (int i = 0; i < len - par; i++)
    {
        printf("%c", answer[i]);
    }
    return 0;
}
