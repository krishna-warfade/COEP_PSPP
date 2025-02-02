#include <stdlib.h>
#include <stdio.h>

char *inttostring(int x) {
    int num, dig = 0, i = 0, len;

    num = x;
    char *p;
    while(num != 0) {
        num = num / 10;
        dig++;
    }
    if(x < 0) {
        len = dig + 2;
        p = (char *)malloc(len * sizeof(char));

        x *= -1;
        p[0] = '-';
        i = len - 2;
    }
    else {
        len = dig + 1;
        i = len - 2;
        p = (char *)malloc(len * sizeof(char));
    }
    if(x == 0) {
        p = (char *)malloc(2 * sizeof(char));

        p[0] = '0';
        p[1] = '\0';
        return p;
    }
    while(x > 0 && x != 0) {
        p[i--] = '0' + (x % 10);
        x = x / 10;
    }
    p[len - 1] = '\0';
    return p;
}
int main() {
	printf("%s\n", inttostring(-964));
	return 0;
}
