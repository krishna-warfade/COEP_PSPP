#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024
int readline(char *s, int size)
{
	char *p = s;
	while (((s - p) < size - 1) && (*s = getchar()) && (*s != '\n'))
		s++;
	*s = '\0';
	return (s - p); // len

	/* Like : char ch;
	int len = 0;
	while(read(fd, &ch, 1) && ch != '\n') {
		line[len] = ch;
		len++;
	}
	line[len] = '\0';
	return len; */
}

int main()
{
	char **p;
	char line[SIZE];
	int len, n, i = 0, max;

	scanf("%d", &n);
	getchar(); // eat the newline
	/* malloc pointer array */
	p = (char **)malloc(n * sizeof(char *));
	if (p == NULL)
	{
		printf("malloc failed!\n");
		return 1;
	}
	/* read all strings in malloced arrays */
	for (i = 0; i < n; i++)
	{
		len = readline(line, SIZE);		// len != 0
		p[i] = (char *)malloc(len + 1); // or malloc(strlen(line) + 1);
		if (p[i] == NULL)
		{
			printf("malloc failed!\n");
			return 1;
		}
		strcpy(p[i], line);
	}

	/* find max len string */
	max = 0;
	for (i = 1; i < n; i++)
	{
		if (strlen(p[i]) > strlen(p[max]))
			max = i;
	}
	printf("%s\n", p[max]);

	/* this is crucial */
	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);

	return 0;
}
