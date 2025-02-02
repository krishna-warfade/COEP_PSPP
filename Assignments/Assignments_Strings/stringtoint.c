long stringtoint(char *str) {
    int num = 0, i;
    int sign = 1;
    
	if(str[i] == '-') {
		sign *= -1;
		str++;
	}
        while(*str && (str[i] >= '0' && str[i] <= '9'))
		num = num * 10 + (str[i++] - '0');
	return sign * num;
}
