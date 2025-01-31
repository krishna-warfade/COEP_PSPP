#include <stdio.h>
int main()
{
	int a, f, x = 0;
	x = scanf("%d", &a);
	f = a;
	if (x == -1)
	{
		printf("error");
		return 0;
	}
	else
	{
		while (scanf("%d", &a) == 1)
		{
		}
	}
	printf("%d\n", (a - f));
	return 0;
}
