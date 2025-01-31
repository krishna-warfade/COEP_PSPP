#include <stdio.h>
int main()
{
	float cp, sp, amt;
	scanf("%f%f", &cp, &sp);
	if (sp > cp) {
		amt = ((sp - cp) / cp) * 100;
		printf("profit: %.2f%%", amt);
	} else if (cp > sp) {
		amt = ((cp - sp) / cp) * 100;
		printf("loss: %.2f%%", amt);
	} else {
		printf("no-profit, no-loss");
	}
	return 0;
}
