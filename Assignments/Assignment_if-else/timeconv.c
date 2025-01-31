#include <stdio.h>
int main()
{
	int num, result;
	char input;
	scanf("%d %c", &num, &input);
	if (input == 'f') {
		result = (num * 12);
		printf("%d\n", result);
	} else if (input == 'y') {
		result = (num * 36);
		printf("%d\n",result);
	} else if (input == 'm') {
		result = (num * 63360);
		printf("%d\n",result);
	} else {
		printf("error\n");
	}
	return 0;
}
