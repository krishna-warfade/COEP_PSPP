/*
Write a C program which :

Reads a sequence of following structs  as input, and stores them in an array. 

struct data { char name[16]; int marks; }

Then the program sorts the array of strings using bubble sort., in dictionary order on name.

Then the program prints the structs one after another, one struct on one line each.
*/

#include <stdio.h>
#include <string.h>
#define SIZE 256

struct data {
	char name[16];
	int marks;
};
        /*BUBBLE SORT on struct data*/
void sortdata(struct data data[], int len) {
	int i, j;

	struct data temp[len];
	for (i = 0; i < len; i++) {
		for (j = 0; j < len- i - 1; j++) {
			if (strcmp(data[j].name, data[j + 1].name) > 0) {
				temp[j] = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp[j];
			}
		}
	}	
}

int main() {
	int i, len;

	struct data data[SIZE];
			/*TAKE DATA AS INPUT*/

	while (scanf("%s %d", data[i].name, &data[i].marks) == 2)
		i++;
	len = i;

			/*BUBBLE SORT on struct data*/
	
	sortdata(data, len);
	
			/*PRINT THE SORTED DATA*/
	
	for (int j = 0; j < len; j++)
		printf("%s %d\n", data[j].name, data[j].marks);
	return 0;
}
