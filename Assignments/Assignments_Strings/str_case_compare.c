#include <stdio.h>

int strcasecompare(char *a, char *b) {
    int i;

    for(i = 0; a[i] == b[i]; i++)
        if(a[i] == '\0') return 0;
    if ((a[i] - b[i]) > 0) return 1;
    else return -1;
}
int main(void)
{
    char *a = "ab", *b = "hi";

    printf("%d\n", strcasecompare(a, b));
    return 0;
}
