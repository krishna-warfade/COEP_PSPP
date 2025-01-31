#include <stdio.h>
int main()
{
	char ch;
	scanf("%c", &ch);
	switch (1)
	{
	case 1:
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			printf("Alphabet\n");
		}
		break;
		printf("out of switch");
		return 0;
	}
}
