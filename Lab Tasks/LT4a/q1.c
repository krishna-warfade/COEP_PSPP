
#include <stdio.h>
int main()
{
    int a, b, result;
    char operator;
    // Read two numbers and an operator from the user
    scanf("%d %d", &a, &b);
    scanf(" %c", &operator);
    // erform the operation based on the operator
    switch (operator)
    {
    case '+':
        result = a + b;
        printf("%d\n", result);
        break;
    case '-':
        result = a - b;
        printf("%d\n", result);
        break;
    case '*':
        result = a * b;
        printf("%d\n", result);
        break;
    case '/':
        result = a / b;
        printf("%d\n", result);
        break;
    default:
        printf("error\n");
        break;
    }
    return 0;
}
