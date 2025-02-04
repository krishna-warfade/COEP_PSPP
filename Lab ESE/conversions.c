/*
Write a program that reads weight in pound or ounce or stone and converts it into kg.
Input possibilities:
<number> lb
<number> ou
<number> st

use:
1 ounce = 0.0283495 kg
1 pound(lb) = 0.453592 kg
1 stone = 6.35029 kg  

print the answer upto two decimal places.
Print "0.00 kg" on error in input.
*/

#include <stdio.h>
#include <string.h>
#define OUNCE 0.0283495
#define POUND 0.453592
#define STONE 6.35029
#define SIZE 8

		/*Function to identify from_unit for conversion to_kg*/

int getunit(char *unit)
{
	if (strlen(unit) <= 2) {
		if ((unit[0] == 'o' && unit[1] == 'u')) {
			return 1;
		} else if ((unit[0] == 'l' && unit[1] == 'b')) {
			return 2;
		} else if ((unit[0] == 's' && unit[1] == 't')) {
			return 3;
		} else {
			return -1;
		}
	}
	return -1;
}

int main() {
	double num;
	char unit[SIZE];

	scanf("%lf", &num);
	if (num < 0) {
		printf("0.00 kg\n");
		return 1;
	}
	scanf("%s", unit);
	switch(getunit(unit)) { // Used switch-case to improve readibility
	case 1:
			printf("%.2lf kg\n", num * OUNCE);
			break;
	case 2:
			printf("%.2lf kg\n", num * POUND);
			break;
	case 3:
			printf("%.2lf kg\n", num * STONE);
			break;
	case -1:
			printf("0.00 kg\n");
			break;
	default:
			printf("0.00 kg\n");
			break;
	}
	return 0;
}
