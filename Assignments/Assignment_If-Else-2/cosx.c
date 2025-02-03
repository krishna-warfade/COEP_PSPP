//cos(x) = 1 - x ^ 2 / 2! + x ^ 4 / 4! - x ^ 6 / 6! + ...

#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main() {
	double x;
	int sign = -1, i = 2;
	float cosx = 1.0, term = 1.0, precision = 1e-6;

	scanf("%lf", &x);
	while (x > PI)
		x -= 2 * PI;
	while (fabs(term) > precision) {
		term = (term * (x * x)) / ((i) * (i - 1));
		cosx += (sign * term);
		sign *= -1;
		i += 2;
	}
	printf("%.4lf", cosx);
	return 0;
}
