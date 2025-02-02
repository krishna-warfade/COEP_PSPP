/*
Sum of (1/n) terms
*/

#include <stdio.h>

int main() {
	float terms, sum = 0, n = 1, i = 0;

	scanf("%f", &terms);
	if (terms == 0) {
		printf("0.00\n");
		return 0;
	}
	while (i < terms) {
		sum = sum + (1 / n);
		n = n + 1;
		i = i + 1;
	}
	printf("%.2f\n", sum);
	return 0;
}
