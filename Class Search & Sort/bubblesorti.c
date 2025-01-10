#include <stdio.h>
#define SIZE 16
struct student {
	int mis;
	char name[32];
	float marks;
};
typedef struct student student;
void print_records(student a[], int len) {
	int i;
	printf("-------------\n");
	for(i = 0; i < len; i++)
		printf("%d %s %.2f\n", a[i].mis,
			a[i].name, a[i].marks);
}
void bubblesort(student a[], int len) {
	int i, j;
	int count = 0;
	student t;
	for(j = 0; j < len - 1; j++) {
			i = 0;
			count = 0;
			while(i < len - j - 1) {
				if(a[i].mis > a[i + 1].mis) {
					t = a[i];
					a[i] =a[i + 1];
					a[i + 1] = t;
					count++;
				}
				i++;
			}
			if(count == 0)
				return;
	}
}
int main() {
	student a[SIZE];
	int len = 0;
	int mis, ret;	
	while(len < SIZE && scanf("%d%s%f", &a[len].mis, 
			a[len].name, &a[len].marks) == 3)
		len++;
	print_records(a, len);
	bubblesort(a, len);
	print_records(a, len);
	return 0;	
}
