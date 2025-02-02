#include <stdio.h>
#include <math.h>
int main()
{
    int sum = 1, n, a = 1, sign = -1;

    scanf("%d", &n);
    if (n == 1) {
        printf("1\n1\n");
        return 0;
    }
    printf("1");
    while (fabs(sum) < n) {
        a = fabs(a) + 2;
        a = sign * a;
        sum = sum + a;
        sign = -1 * sign;
        if (a > 0)
            printf("+%d", a);
        else
            printf("%d", a);
    }
    printf("\n%d\n", sum);
    return 0;
}
