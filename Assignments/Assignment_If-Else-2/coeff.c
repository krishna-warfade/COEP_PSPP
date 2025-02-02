#include <stdio.h>
int facto(int num)
{
	if (num == 0 || num == 1) {
		return 1;
	}
	int i, fact = num;

	i = num - 1;
	while (i > 1) {
		fact = fact * i;
		i = i - 1;
	}
	return fact;
}
int main() {
	int n, r = 0, coeff;

	scanf("%d", &n);
	while (r <= n) {
		coeff = (facto(n) / ((facto(n - r)) * facto(r)));
		r++;
		printf("%d ", coeff);
	}
	return 0;
}
