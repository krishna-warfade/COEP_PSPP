#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd, chars, words, lines, flag;
	char ch;

	fd = 0;
	chars = 0;
	words = 0;
	lines = 0;
	flag = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("file not opened\n");
		return 1;
	}
	while (read(fd, &ch, 1)) {
		++chars;

		if (ch == '\n')
			++lines;

		if (ch == ' ' || ch == '\t' || ch == '\n') {
			flag = 0;
		} else if (flag == 0) {
			flag = 1;
			++words;
		}
	}
	if (ch != '\n' && ch)
		++lines;

	printf("%d %d %d %s\n", chars, words, lines, argv[1]);
	close(fd);
	return 0;
}
