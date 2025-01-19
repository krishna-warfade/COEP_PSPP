#include <stdio.h>
int main()
{
	float ip, dr, fp;

	scanf(" %f %f", &ip, &dr);
	fp = (ip - ((ip * dr) / 100));
	printf("%.2f\n", fp);
	return 0;
}
