#include <stdio.h>
struct student {
	int mis;
	char name[32];
	float marks;
};
#define SIZE 16
typedef struct student student;
void print_records(student a[], int len) {
	int i;
	printf("-----array-------\n");
	for(i = 0; i < len; i++)
		printf("%d %s %.2f\n", a[i].mis, 
			a[i].name, a[i].marks);
}
/* linear search;
 * searches for the record with mis id = mis
 * in the array a[], upto len,
 * returns the index of the element found
 * returns -1 if not found
 */
void insert(student a[], int len, int i){
	/* assume that a[0..i-1] is already sorted
 	 * and insert a[i] such that 
 	 * a[0..i] is sorted
	 */
	student t;
	t = a[i];
	while(i >= 1 && a[i - 1].mis > t.mis) {
		a[i] = a[i - 1];
		i--;	
	}
	a[i] = t;
	return;
}
void inssort(student a[], int len) {
	int i;
	i = 1;
	while(i < len) {
		//move the ith entry into 
		//already sorted 0..i-1th entries
		insert(a, len, i);
		i++;
	}
}
int main() {
	student a[SIZE];
	int len = 0;
	int mis, ret;

	while(len < SIZE && scanf("%d%s%f", &a[len].mis, a[len].name,
			&a[len].marks) == 3)
		len++;	
	print_records(a, len);	
	inssort(a, len);
	print_records(a, len);	

	return 0;	
}
