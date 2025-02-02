int len(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
char *strdupl(const char *s)
{
    char *result = (char *)malloc(16);
    char *q = result;

    while ((*result++ = *s++))
        ;
    return q;
}
