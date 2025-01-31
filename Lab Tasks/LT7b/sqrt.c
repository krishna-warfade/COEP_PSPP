#include <stdio.h>

float sqroot(float x)
{
	float m;
	int i = 1;

	m = x / 2.00;
	while (i >= 1e-6)
	{
		while (m * m > x)
		{
			m = m - i;
		}
		i /= 10;
	}
	return m;
}
int main()
{
	float x, y;

	scanf("%f", &x);
	y = sqroot(x);
	printf("%f", y);
	return 0;
}
