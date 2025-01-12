#include <stdio.h>
int main()
{
	int value, notes100 = 0, notes50 = 0, notes20 = 0, notes5 = 0;
	scanf("%d", &value);
	if(value >= 100) {
		notes100 = value / 100;
		value = value % 100;
		printf("100 %d ", notes100);
	}
	if(value >= 50) {
		notes50 = value / 50;
		value = value % 50;
		printf("50 %d ", notes50);
	}
	if(value >= 20) {
		notes20 = value / 20;
		value = value % 20;
		printf("20 %d ", notes20);
	}
	if(value >= 5) {
		notes5 = value / 5;
		value = value % 5;
		printf("5 %d ", notes5);
	}
	if(value >=1) {
		printf("1 %d ", value);
	}		
	printf("%d\n", notes100 + notes50 + notes20 + notes5 + value);
	return 0;
}
