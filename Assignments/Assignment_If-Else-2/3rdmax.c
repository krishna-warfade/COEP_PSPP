#include <stdio.h>
#include <limits.h>

int main()
{
	int i = 0, num, max1, max2, max3;

	max1 = max2 = max3 = INT_MIN;
	while (scanf("%d", &num) != -1) {
		if (num >= max1) {
			max3 = max2;
			max2 = max1;
			max1 = num;
		} else if (num >= max2) {
			max3 = max2;
			max2 = num;
		} else if (num >= max3) {
			max3 = num;
		}
		i++; // counter for number of inputs
	}
	if (i < 3) { // Case : less than 3 inputs
		printf("\nNot Found\n");
	} else {
		printf("\n%d\n", max3);
	}
	return 0;
}
