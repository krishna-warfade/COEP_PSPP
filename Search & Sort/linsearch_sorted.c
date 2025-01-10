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
	for(i = 0; i < len; i++)
		printf("%d %s %.2f\n", a[i].mis,
			a[i].name, a[i].marks);
}
/* searches for a record matching 'mis' in the array
 * a[], upto length = len
 * returns the index of the first record found
 * returns -1 if not found
 */
int search_mis(student a[], int len, int mis) {
	int i;
	for(i = 0; i < len; i++) {
		if(a[i].mis == mis)
			return i;
		if(a[i].mis > mis)
			return -1;
	}
	return -1;	
}
int main() {
	student a[SIZE];
	int len = 0;
	int mis, ret;	
	scanf("%d", &mis);
	while(len < SIZE && scanf("%d%s%f", &a[len].mis, 
			a[len].name, &a[len].marks) == 3)
		len++;
	print_records(a, len);
	ret = search_mis(a, len, mis);
	if(ret == -1) 
		printf("not found\n");
	else
		printf("%d %s %.2f\n", a[ret].mis, a[ret].name, a[ret].marks);
	return 0;	
}
