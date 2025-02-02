#include <stdio.h>
int main()
{
	int a = 1, b, terms, i = 0;

	scanf("%d", &terms);
	while (i < terms) {
		printf("%d ", a);
		b = a + a;
		a = b;
		i++;
	}
	return 0;
}
