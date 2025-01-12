#include <stdio.h>
int main()
{
	int grade, credit;
	float sgpa, totalCredits = 0, sum = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &credit);
		scanf("%d", &grade);
		sum += (credit * grade);
		totalCredits += credit;
	}
	sgpa = (sum / totalCredits);
	printf("%.6f", sgpa);
	return 0;
}
