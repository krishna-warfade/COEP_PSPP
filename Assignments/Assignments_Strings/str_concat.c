char *strconcat(char *dest, const char *src)
{
	char *p = dest;

	while(*dest != '\0') {
		dest++;
	}
	while(*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return p;
}

