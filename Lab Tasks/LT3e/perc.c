#include <stdio.h>
int main() {
	float phy, chem, bio, math, comp;
	float Percentage = 0.00;

	scanf("%f %f %f %f %f", &phy, &chem, &bio, &math, &comp);
	Percentage = ((phy + chem + bio + math + comp) / 5);
	printf("Percent = %.2lf%%\n", Percentage);
	if (Percentage >= 90) {
		printf("Grade A\n");
		return 0;
	}
	if (Percentage >= 80) {
		printf("Grade B\n");
		return 0;
	}
	if (Percentage >= 70) {
		printf("Grade C\n");
		return 0;
	}
	if (Percentage >= 60) {
		printf("Grade D\n");
		return 0;
	}
	if (Percentage >= 40) {
		printf("Grade E\n");
		return 0;
	}
	if (Percentage < 40) {
		printf("Grade F\n");
		return 0;
	}
	return 0;
}
