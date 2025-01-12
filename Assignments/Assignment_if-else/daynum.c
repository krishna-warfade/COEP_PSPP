#include <stdio.h>
int main() {
int month, date, result;
scanf("%d%d", &month, &date);

/*printf("date = %d and month = %d\n", date, month);*/

	if(date <= 31 && month == 1) {
		result = (date + 0);
		printf("%d\n", result);
				      }
	else if(date > 31 && month == 1) {
	printf("0\n");
	     }
	
	
	if(date <= 28 && month == 2) {
		result = (date + 31);
		printf("%d\n",result);
				     }	     
	else if(date > 28 && month == 2) {
	printf("0\n");
	     }
	     
	if(date <= 31 && month == 3) {
		result = (date + 59);
		printf("%d\n", result);
				      }
	else if(date > 31 && month == 3) {
	printf("0\n");
	     }
	     
	if(date <= 30 && month == 4) {
		result = (date + 90);
		printf("%d\n", result);
				      }
	else if(date > 30 && month == 4) {
	printf("0\n");
	     }
	     
	if(date <= 31 && month == 5) {
		result = (date + 120);
		printf("%d\n", result);
				      }
	else if(date > 31 && month == 5) {
	printf("0\n");
	     }
	     
	if(date <= 30 && month == 6) {
		result = (date + 151);
		printf("%d\n", result);
				      }
	else if(date > 30 && month == 6) {
	printf("0\n");
	     }
	     
	if(date <= 31 && month == 7) {
		result = (date + 181);
		printf("%d\n", result);
				      }
	else if(date > 31 && month == 7) {
	printf("0\n");
	     }
	     
	if(date <= 31 && month == 8) {
		result = (date + 212);
		printf("%d\n", result);
				      }
	else if(date > 31 && month == 8) {
	printf("0\n");
	     }
	 
	if(date <= 30 && month == 9) {
		result = (date + 243);
		printf("%d\n", result);
				      }
	else if(date > 30 && month == 9) {
	printf("0\n");
	     }
	     
	if(date <= 31 && month == 10) {
		result = (date + 273);
		printf("%d\n", result);
				      }
	else if(date > 31 && month == 10) {
	printf("0\n");
	     }
	     
	if(date <= 30 && month == 11) {
		result = (date + 304);
		printf("%d\n", result);
				      }
	else if(date > 30 && month == 11) {
	printf("0\n");
	     }
	     
	if(date <= 31 && month == 12) {
		result = (date + 334);
		printf("%d\n", result);
				      }
	else if(date > 31 && month == 12) {
	printf("0\n");
	     }
return 0;
}
