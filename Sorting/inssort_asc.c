#include <stdio.h>
#define SIZE 16
int main()
{
    int a[SIZE] = {5, 4, 10, 1, 6, 2};
    int len = 6;
    
    printf("Before Sorting : \n");
    for(int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
    int i, j, temp;
    for(int i = 1; i < len; i++) {
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
            }
    printf("After Sorting : \n");
    for(i = 0; i < len; i++)
        printf("%d ", a[i]);
    return 0;
}
