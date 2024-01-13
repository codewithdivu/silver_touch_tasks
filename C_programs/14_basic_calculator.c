#include <stdio.h>

int main()
{

    char operator;
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    double num1, num2;
    printf("Enter two operands: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator)
    {
    case '+':
        printf("Sum is %.1lf", num1 + num2);
        break;
    case '-':
        printf("Substraction is %.1lf", num1 - num2);
        break;
    case '*':
        printf("Multiplication is %.1lf", num1 * num2);
        break;
    case '/':
        printf("Division is %.1lf", num1 / num2);
        break;
    default:
        printf("please enter valid operator");
    }

    return 0;
}
