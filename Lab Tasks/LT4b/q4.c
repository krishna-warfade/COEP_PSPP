#include <stdio.h>
int main()
{
	int a, b, min;
	b = scanf("%d", &a);
	min = a;
	if (b == -1)
	{
		printf("error");
		return 0;
	}
	else
	{
		while (scanf("%d", &a) == 1)
		{
			if (a < min)
			{
				min = a;
			}
		}
	}
	printf("%d\n", min);
	return 0;
}
