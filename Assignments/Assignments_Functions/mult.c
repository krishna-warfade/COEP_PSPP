int add(int a, int b)
{
  return a + b;
}
int mult(int x, int y)
{
  int i = 0, res = 0, sign;

  (y < 0) ? (sign = -1) : (sign = 1);
  while (i < y * sign) {
    res += add(0, x);
    i++;
  }
  return res * sign;
}
