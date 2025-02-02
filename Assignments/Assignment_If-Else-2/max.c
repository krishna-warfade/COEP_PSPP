#include <stdio.h>
#include <limits.h>

int main()
{
	int num, max = INT_MIN;

	while (scanf("%d", &num) != -1) {
		if (num >= max)
			max = num;
	}
	printf("%d\n", max);
	return 0;
}
