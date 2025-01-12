#include <stdio.h>
int main() {
int num=0, month;
scanf("%d", &num);
if(num >= 1 && num <=31) {
	month = 1;
	printf("%d %d\n", num, month);
	}
else if(num > 31 && num <= 59) {
	month = 2;
	num = num-31;
	printf("%d %d\n", num, month);
	}
else if(num > 59 && num <= 90) {
	month = 3;
	num = num-59;
	printf("%d %d\n", num, month);
	}
else if(num > 90 && num <= 120) {
	month = 4;
	num = num-90;
	printf("%d %d\n", num, month);
	}
else if(num > 120 && num <= 151) {
	month = 5;
	num = num-120;
	printf("%d %d\n", num, month);
	}
else if(num > 151 && num <= 181) {
	month = 6;
	num = num-151;
	printf("%d %d\n", num, month);
	}
else if(num > 181 && num <= 212) {
	month = 7;
	num = num-181;
	printf("%d %d\n", num, month);
	}
else if(num > 212 && num <= 243) {
	month = 8;
	num = num-212;
	printf("%d %d\n", num, month);
	}
else if(num > 243 && num <= 273) {
	month = 9;
	num = num-243;
	printf("%d %d\n", num, month);
	}
else if(num > 273 && num <= 304) {
	month = 10;
	num = num-273;
	printf("%d %d\n", num, month);
	}
else if(num > 304 && num <= 334) {
	month = 11;
	num = num-304;
	printf("%d %d\n", num, month);
	}
else if(num > 334 && num <= 365) {
	month = 12;
	num = num-334;
	printf("%d %d\n", num, month);
	}
else {
	printf("invalid\n");
      }
return 0;
}
