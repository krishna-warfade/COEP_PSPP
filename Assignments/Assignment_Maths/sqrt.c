#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	double s, det;
	
	scanf("%d %d %d", &a, &b, &c);
	det = (b * b) - (4 * a * c);
	s = sqrt(det);
	if (s < 0 || a == 0)
	{
		printf("can't find roots\n");
	} else {
		double root1 = ((-1 * b) + s) / (2 * a);
		double root2 = ((-1 * b) - s) / (2 * a);
		printf("%.6lf %.6lf", root1, root2);
	}
	return 0;
}
