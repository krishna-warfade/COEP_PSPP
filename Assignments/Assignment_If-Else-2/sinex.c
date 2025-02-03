#include <stdio.h>
#include <math.h>
int main(void)
{
	double x, sinex, term;
	int i = 1;

	scanf("%lf", &x);
	term = x;
	sinex = x;
	while (fabs(term) > 0.000001) {
		term = (term * x * x) / ((2 * i + 1) * (2 * i));
		if (i % 2 == 1) {
			sinex = sinex - term;
		}
		else {
			sinex = sinex + term;
			i++;
		}
	}
	printf("%.6lf\n", sinex);
	return 0;
}
