#include <stdio.h>
int main()
{
	int num = 0, a = 0;
	double avg, sum = 0, n;
	scanf("%lf", &n);
	if (n <= 0)
	{
		printf("0.0000\n");
		return 1;
	}

	while (n > a)
	{
		scanf("%d", &num);
		sum = sum + num;
		a = a + 1;
	}
	avg = (sum / n);
	printf("%0.4lf\n", avg);
	return 0;
}
