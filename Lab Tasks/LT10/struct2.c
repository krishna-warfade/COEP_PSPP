#include <stdio.h>
struct point
{
	int x, y, z;
};
void print_records(struct point a[], int n)
{
	int i;
	printf("----array---\n");
	for (i = 0; i < n; i++)
		printf("%d %d %d\n", a[i].x, a[i].y, a[i].z);
	return;
}
void insert(struct point a[], int n, struct point t, int index)
{
	int i;
	for (i = n; i > index; i--)
		a[i] = a[i - 1];
	a[index] = t;
	return;
}
int main()
{
	int n, i, index;
	struct point a[16], t;

	/* read n and records */
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);

	print_records(a, n);

	/* read index and point to be inserted */
	scanf("%d", &index);
	scanf("%d%d%d", &t.x, &t.y, &t.z);

	insert(a, n, t, index);

	print_records(a, n + 1);
	return 0;
}
