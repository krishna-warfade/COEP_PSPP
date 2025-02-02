#include <stdio.h>
int main()
{
	int n1, n2, prev = 1, curr = 2, next;

	scanf("%d %d", &n1, &n2);
	int max = n1;
	int min = n2;

	if (n2 > max) {
		max = n2;
		min = n1;
	}
	while (curr <= max) {
		if (min == prev && max == curr)	{
			printf("yes\n");
			return 0;
		}
		next = prev + curr;
		prev = curr;
		curr = next;
	}
	if (min != prev || max != curr)	{
		printf("no\n");
		return 0;
	}
	return 0;
}
