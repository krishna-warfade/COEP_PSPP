/*
Write a C program that reads a sequence of real numbers, until EOF,  and prints the minimum and maximum (in that order)
upto 2 decimal points. Use double.
*/

#include <stdio.h>
#include <limits.h>

int main() {
	double num, min, max;

	num = 0.00;
	min = INT_MAX;
	max = INT_MIN;

	while ((scanf("%lf", &num)) != EOF) {
		if (num > max)
			max = num;
		if (num < min)
			min = num;
	}

	/*CASE OF NO INPUT*/

	if (max == INT_MIN || min == INT_MAX) return 0;

	printf("%.2lf %.2lf\n", min, max);
	return 0;
}

