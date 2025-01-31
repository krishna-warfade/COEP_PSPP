#include <stdio.h>
#include <limits.h>

int maxabsdiff(int a[], int len)
{
	int maxdiff, diff, i;
	maxdiff = INT_MIN;

	for (i = 0; i < len - 1; i++)
	{
		diff = a[i] - a[i + 1];
		if (diff < 0)
			diff = -diff;
		if (diff > maxdiff)
			maxdiff = diff;
	}
	return maxdiff;
}
int main()
{
	// int arr[16] = {1, -1, 2, -3, 3, -3};
	// printf("%d\n", maxabsdiff(arr, 6));

	// int arr[16] = {1, -1};
	// printf("%d\n", maxabsdiff(arr, 2));

	// int arr[7] = {1, 2, -1, 3, -4, 5, 7};
	// printf("%d\n", maxabsdiff(arr, 7));

	int arr[16] = {1, 0, -1, 2, 3, -4, 100};

	printf("%d\n", maxabsdiff(arr, 7));

	// int arr[16] = {1, 1, 1, 2};
	// printf("%d \n", maxabsdiff(arr, 4));
}
