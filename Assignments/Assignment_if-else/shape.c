#include <stdio.h>
int main()
{
	int l, b, h, s, r;
	float area, peri;
	char shape, op;
	scanf("%c %c", &shape, &op);
	if(shape == 't' && op == 'a') {
			scanf("%d %d", &b, &h);
			area = ((0.5) * b * h);
			printf("%.2f\n", area);
	} else if(shape == 't' && op == 'p') {
			scanf("%d %d %d", &l, &b, &h);
			peri = (l+b+h);
			printf("%.2f\n", peri);
	} else if(shape == 'r' && op == 'a') {
			scanf("%d%d", &l, &b);
			area = (l*b);
			printf("%.2f\n", area);
	} else if(shape == 'r' && op == 'p') {
			scanf("%d %d", &l, &b);
			peri = (2*(l+b));
			printf("%.2f\n", peri);
	} else if(shape == 's' && op == 'a') {
			scanf("%d", &s);
			area = (s*s);
			printf("%.2f\n", area);
	}else if(shape == 's' && op == 'p') {
			scanf("%d", &s);
			peri = (4*s);
			printf("%.2f\n", peri);
	} else if(shape == 'c' && op == 'a') {
			scanf("%d", &r);
			area = (3.14*r*r);
			printf("%.2f\n", area);
	} else if(shape == 'c' && op == 'p') {
			scanf("%d", &r);
			peri = (2 * 3.14 * r);
			printf("%.2f\n", peri);
	} else {
	printf("error\n");
	}
	return 0;
}	     
