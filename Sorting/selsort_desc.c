#include <stdio.h>
#define SIZE 16
void swap(int a[SIZE], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int main()
{
    int a[SIZE] = {7, 4, 10, 8, 3, 1};
    int len = 6;
    printf("Before Sorting : \n");
    for(int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
    int i, j, min;
    for(int i = len - 1; i > 0; i--) {
        min = i;
        for(j = i - 1; j >= 0; j--) {
            if(a[j] < a[min])
                min = j;
        }
        if(min != i)
            swap(a, i, min);
    }
    printf("After Sorting : \n");
    for(i = 0; i < len; i++)
        printf("%d ", a[i]);
    return 0;
}
