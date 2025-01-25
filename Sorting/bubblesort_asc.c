#include <stdio.h>
#define SIZE 16

void swap (int a[16], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main() {
    int a[SIZE] = {5, 4, 10, 1, 6, 2};
    int len = 6;
    printf("Before Sorting : \n");
    for(int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");
    int i, j;
    for(int i = 0; i < len - 1; i++) {
        for(j = 0; j < len - i - 1; j++) {
            if(a[j] > a[j + 1]) swap(a, j, j + 1);
        }
    }
    printf("After Sorting : \n");
    for(i = 0; i < len; i++)
        printf("%d ", a[i]);
    return 0;
}
