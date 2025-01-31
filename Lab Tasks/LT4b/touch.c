#include <stdio.h>
int main()
{
    int a, b, c;

    scanf("%d", &a);              // reads an integer value into variable 'a'.
    b = (scanf("%d %d", &a, &c)); // attempts to read two integers, which will be stored in 'a' and 'c'.
                                  // assigns the return value of scanf to 'b'.
    printf("a = %d\n", a);        // prints the value of 'a' after the second scanf call.
    printf("b = %d\n", b);        // prints the return value of the second scanf call, which is the number of successful input items.
    return 0;
}
