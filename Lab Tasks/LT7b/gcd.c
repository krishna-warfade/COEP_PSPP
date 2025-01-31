#include <stdio.h>
int g_c_d(int p, int q)
{
	int max, min, n = 2, gcd;

	max = (p > q) ? p : q;
	min = (p > q) ? q : p;
	while (min >= n)
	{
		if ((max % n == 0) && (min % n == 0))
		{
			gcd = n;
			n++;
		}
		else
			n++;
	}
	return gcd;
}
int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d\n", g_c_d(a, b));
	return 0;
}
