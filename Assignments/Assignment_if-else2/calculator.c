#include <stdio.h>

int main()
{
    int op1, op2, ans, x;
    char opr1, opr2;

    while (1)
    {
        x = scanf("%d", &op1);
        if (x == EOF) {
            break;
        }
        if (x != 1) {
            printf("bad op1\n");
            return 0;
        }
        if (scanf(" %c", &opr1) != 1) {
            printf("bad opr1\n");
            return 0;
        }
        if (opr1 == '<' || opr1 == '>') {
            if (scanf(" %c", &opr2) != 1)
            {
                printf("bad opr2\n");
                return 0;
            }
        }
        if (scanf("%d", &op2) != 1) {
            printf("bad op2\n");
            return 0;
        }
        switch (opr1)
        {
        case '+':
            ans = op1 + op2;
            break;
        case '-':
            ans = op1 - op2;
            break;
        case '*':
            ans = op1 * op2;
            break;
        case '/':
            ans = op1 / op2;
            break;
        case '%':
            ans = op1 % op2;
            break;
        case '|':
            ans = op1 | op2;
            break;
        case '&':
            ans = op1 & op2;
            break;
        case '<':
            if (opr2 == '<') {
                ans = op1 << op2;
            } else {
                printf("opr1 %c != opr2 %c\n", opr1, opr2);
                return 0;
            }
            break;
        case '>':
            if (opr2 == '>') {
                ans = op1 >> op2;
            } else {
                printf("opr1 %c != opr2 %c\n", opr1, opr2);
                return 0;
            }
            break;
        default:
            printf("bad opr1\n");
            return 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
