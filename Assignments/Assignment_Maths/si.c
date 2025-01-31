#include <stdio.h>
int main()
{
    float p, r, y, si, fp;

    scanf("%f %f %f", &p, &r, &y);
    fp = p + (si = (p * r * y) / 100);
    printf("%f\n", fp);
    return 0;
}
