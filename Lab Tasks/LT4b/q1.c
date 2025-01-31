#include <stdio.h>
int main()
{
	int num = 0, sum = 0, Nsum = 0;
	scanf("%d", &num);
	while (num != -1)
	{
		sum = sum + num;
		scanf("%d", &num);
	}
	Nsum = (sum - 1);
	printf("%d\n", Nsum);
	return 0;
}
