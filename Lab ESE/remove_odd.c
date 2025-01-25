/*Write a C function, which given an array of integers, removes all odd numbers from the array, maintaining the order of remaining numbers. The function returns the new length of the array. Assume that all numbes will be >=0

int removeodd(int a[], int len);*/

#include <stdio.h>
        /*FUNCTION TO CHECK IF ARRAY ELEMENT IS ODD*/
int is_odd(int num) {
	if (num % 2) {
		return 1;
	}
	return 0;
}
        /*FUNCTION TO REMOVE ODD ARRAY ELEMENTS*/
int removeodd(int a[], int len)
{
	int newlen, i, odd;

	newlen = 0;
	for (i = 0; i < len; i++) {
		odd = is_odd(a[i]);
		if (!odd) {
			a[newlen] = a[i];
			newlen++;
		}
	}
	return newlen;
}

