#include <stdio.h>
#include <limits.h>

int main()
{
	int first = INT_MIN;
	int second = INT_MIN;
	int third = INT_MIN;
	int fourth = INT_MIN;
	int count = 0;
	int num;

	while (scanf("%d", &num) != EOF && (count < 4 || count > 4))
	{
		if (num >= first)
		{
			fourth = third;
			third = second;
			second = first;
			first = num;
		}
		else if (num >= second)
		{
			fourth = third;
			third = second;
			second = num;
		}
		else if (num >= third)
		{
			fourth = third;
			third = num;
		}
		else if (num >= fourth)
		{
			fourth = num;
		}
		count++;
	}
	printf("%d %d %d %d\n", fourth, third, second, first);
	return 0;
}
