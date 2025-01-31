#include <stdio.h>
#define SIZE 128
int main()
{
	int a[SIZE] = {0};
	int i = 0, lena, count = 0, max;

	while (scanf("%d", &a[i]) != -1)
		i++;
	lena = i;
	max = a[0];
	count = 1;
	for (i = 0; i < lena; i++)
	{
		if (a[i] == max)
			count++;
		if (a[i] > max)
			max = a[i];
		count = 1;
	}
	printf("%d %d\n", max, count);
	return 0;
}
