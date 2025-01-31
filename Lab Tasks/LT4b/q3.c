#include <stdio.h>
int main()
{
	char ch = 0;
	while ((ch = getchar()) != '\n')
	{
		if ((ch == 'a' || ch == 'A') || (ch == 'e' || ch == 'E') || (ch == 'i' || ch == 'I') || (ch == 'o' || ch == 'O') || (ch == 'u' || ch == 'U'))
		{
			printf("vowel\n");
		}
		else
		{
			printf("not-vowel\n");
		}
	}
	printf("not-vowel\n");
	return 0;
}
