#include <stdio.h>

int strlength(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return i;
}
char *strchar(char *str, char c) {
    int len = strlength(str);

	if (c == '\0')
		return (str + len);
	for(int i = 0; i < len; i++){
		if(str[i] == c)
			return (str + i);
	}
	return NULL;
}
int main() {
	printf("%s\n", strchar("abhijit", 'h'));
	return 0;
}
