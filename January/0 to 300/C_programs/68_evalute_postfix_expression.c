#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int stack[100];
    int top = -1;

    char str[100];
    printf("please enter the infix string\n");
    gets(str);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            stack[++top] = str[i] - '0';
        }
        else
        {
            int operand1 = stack[top--];
            int operand2 = stack[top--];
            switch (str[i])
            {
            case '+':
                stack[++top] = operand1 + operand2;
                break;
            case '-':
                stack[++top] = operand1 - operand2;
                break;
            case '*':
                stack[++top] = operand1 * operand2;
                break;
            case '/':
                stack[++top] = operand1 / operand2;
                break;
            case '^':
                stack[++top] = pow(operand1, operand2);
                break;
            }
        }
    }

    printf("postfix evaluation for this expression is %d ", stack[top]);

    return 0;
}