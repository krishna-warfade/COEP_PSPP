int min(int p, int q)
{
	int minm;

	minm = p;
	if (q < p) {
		minm = q;
	}
	return minm;
}
