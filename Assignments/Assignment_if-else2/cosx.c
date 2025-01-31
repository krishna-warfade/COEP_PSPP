#include <stdio.h>
#include <math.h>
#define pi 3.14159265359

int main()
{
	double x;
	int sign = -1, i = 2;
	float cosx = 1.0, term = 1.0, precision = 1e-6;

	scanf("%lf", &x);
	while (x > pi)
	{
		x = x - 2 * pi;
	}
	while (fabs(term) > precision)
	{
		term = (term * (x * x)) / ((i) * (i - 1));
		cosx = cosx + (sign * term);
		sign = (sign * (-1));
		i = i + 2;
	}
	printf("%.4lf", cosx);
	return 0;
}
