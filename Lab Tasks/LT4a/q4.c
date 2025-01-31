#include <stdio.h>
int main()
{
	int a, num = 0;
	scanf("%d", &num);
	a = num / 100;
	switch (a)
	{
	case 0:
		if (num < 0)
		{
			printf("Number is negative\n");
			return 0;
		}
		else if (num == 0)
		{
			printf("Number is zero\n");
			return 0;
		}
		printf("Number is less than 100\n");
		break;
	case 1:
		printf("Number is greater than or equal 100 but less than 200\n");
		break;
	case 2:
		printf("Number is greater than or equal 200 but less than 300\n");
		break;
	case 3:
		printf("Number is greater than or equal 300 but less than 400\n");
		break;
	case 4:
		printf("Number is greater than or equal 400 but less than 500\n");
		break;
	case 5:
		printf("Number is greater than or equal 500 but less than 600\n");
		break;
	case 6:
		printf("Number is greater than or equal 600 but less than 700\n");
		break;
	case 7:
		printf("Number is greater than or equal 700 but less than 800\n");
		break;
	case 8:
		printf("Number is greater than or equal 800 but less than 900\n");
		break;
	case 9:
		printf("Number is greater than or equal 900 but less than 1000\n");
		break;
	default:
		printf("Number is greater than or equal to 1000\n");
		break;
	}
	return 0;
}
