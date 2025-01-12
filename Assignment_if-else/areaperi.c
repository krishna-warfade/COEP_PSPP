#include <stdio.h>
int main() {
	char t, ap;
	double base, height, side, radius, a, b, c;
	double area, perimeter; 

	t = getchar();
	getchar();
	ap = getchar();
	getchar();
	//printf("%c %c\n", t, ap);
	if(t != 't' && t != 'r' && t != 's' && t != 'c') {
		printf("error\n");
		return 1;
	}
	if(ap != 'a' && ap != 'p') {
		printf("error\n");
		return 1;
	}
	if(t == 't') { 	/* triangle */
		if(ap == 'a') {
			if(scanf("%lf%lf", &base, &height) != 2) {
			   printf("error\n");
			   return 1;
			}
			area = 0.5 * base * height;
		} else  {
			/* perimeter */
			if(scanf("%lf%lf%lf", &a, &b, &c) != 3) {
			    printf("error");
			    return 1;
			}
			perimeter = a  + b + c;
		} 
	} else if (t == 'r') { /* rectangle */
		if(ap == 'a') {
			if(scanf("%lf%lf", &base, &height) !=2 ) {
			    printf("error");
			    return 1;
			}
			area = base * height;
		} else  {
			/* perimeter */
			if(scanf("%lf%lf", &base, &height) != 2) {
			    printf("error");
			    return 1;
			}
			perimeter = 2.0 * (base + height);
		} 

	} else if (t == 's') {	/* square */
		if(scanf("%lf", &side) !=1) {
		    printf("error");
		    return 1;
		}
		if(ap == 'a') {
			area = side * side;
		} else  {
			/* perimeter */
			perimeter = 4.0 * side;
		} 

	} else { /* circle */
		if(scanf("%lf", &radius) != 1) {
		    printf("error");
		    return 1;
		}
		if(ap == 'a') {
			area = 3.14 * radius * radius;
		} else  {
			/* perimeter */
			perimeter = 3.14 * 2 * radius;
		} 
	}
	if(ap == 'a') {
		printf("%.2lf\n", area);
	} else {
		printf("%.2lf\n", perimeter);
	}
	
	return 0;	
}
