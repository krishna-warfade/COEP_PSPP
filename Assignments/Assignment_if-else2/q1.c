#include <stdio.h>
int facto(int num)
{
	if (num == 0 || num == 1)
		return 1;
	int i, fact = num;
	i = num - 1;
	while (i > 1)
	{
		fact = fact * i;
		i = i - 1;
	}
	return fact;
}
int main()
{
	double x, x_n, prev;
	int n, i = 0;
	scanf("%lf %d", &x, &n);
	prev = x;
	if (x == 1 && n == 1)
	{
		printf("1.00\n");
		return 0;
	}
	while (i < n - 1)
	{
		x_n = prev * x;
		prev = x_n;
		i = i + 1;
	}
	printf("%.2lf", ((x_n) / facto(n)));
	return 0;
}