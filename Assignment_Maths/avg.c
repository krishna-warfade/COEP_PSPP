#include <stdio.h>
int main()
{
    int a, b, c, sum;
    
    scanf("%d%d%d", &a, &b, &c);
    sum = (a + b + c);
    float avg = ((float)sum / 3);
    printf("%.2f", avg);
    return 0;
}
