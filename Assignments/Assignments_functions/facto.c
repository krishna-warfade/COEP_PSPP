unsigned long factorial(unsigned int num)
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
