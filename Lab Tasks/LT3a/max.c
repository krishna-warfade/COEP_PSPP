#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b && a > c)
    {
        printf("%d\n", a);
    }
    if (b > a && b > c)
    {
        printf("%d\n", b);
    }
    if (c > a && c > b)
    {
        printf("%d\n", c);
    }
    if (a == b && b == c)
    {
        printf("%d\n", a);
    }
    return 0;
}
