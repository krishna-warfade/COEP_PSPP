#include <stdio.h>
int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	if (((a + b) > c) && ((c + b) > a) && ((a + c) > b))
		printf("Valid-Triangle\n");
	else
		printf("Invalid-Triangle\n");
	return 0;
}
