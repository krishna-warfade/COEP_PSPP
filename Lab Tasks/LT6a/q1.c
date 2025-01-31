#include <stdio.h>
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int p, q;

	while (scanf("%d %d", &p, &q) != EOF)
		printf("%d\n", max(p, q));
	return 0;
}
