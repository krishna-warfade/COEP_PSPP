#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i;
	double sum = 0.0, avg;

	scanf("%d", &n);
	double *arr = (double *)malloc(n * sizeof(double));
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &arr[i]);
		sum += arr[i];
	}
	printf("%lf\n", sum / n);
	free(arr);
	return 0;
}
