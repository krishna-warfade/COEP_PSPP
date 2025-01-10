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
/* searches for a record matching 'mis' in the array
 * a[], upto length = len
 * returns the index of the first record found
 * returns -1 if not found
 */
int findmin(student a[], int i, int len) {
	int min = a[i].mis;
	int minindex = i;
	int j;
	for(j = i + 1; j < len; j++) 
		if(a[j].mis < min) {
			min = a[j].mis;
			minindex = j;
		}
	return minindex;
}
void selsort(student a[], int len) {
	student t;	
	int i, min;
	i = 0;
	while(i < len - 1) {
		//find the minimum between i and len -1
		min = findmin(a, i, len);
		//move ith minimum to ith position;
		t = a[i];
		a[i] = a[min];
		a[min] = t;
		i++;
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
	selsort(a, len);
	print_records(a, len);
	return 0;	
}
