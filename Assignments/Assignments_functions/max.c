intmax3(int a, int b, int c)
{
	int max;

	max = a;
	if (b >= max && b >= c)
	{
		max = b;
	}
	else if (c >= max && c >= b)
	{
		max = c;
	}
	return max;
}
