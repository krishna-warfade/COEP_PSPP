int len(char *str)
{
	int i = 0;

	while(str[i++] != '\0')
		;
	return i;
}
char *strchar(char *str, char c)
{
	int i;

	if(c == '\0')
		return (str + len(str));
	for(i = 0; i < len(str); i++) {
		if(str[i] == c)
			return (str + i);
	}
	return 0;
}

