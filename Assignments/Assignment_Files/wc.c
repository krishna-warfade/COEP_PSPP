#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd, chars, words, lines, flag;
	char ch, filename[128];

	fd = 0;
	chars = 0;
	words = 0;
	lines = 0;
	flag = 0;

	scanf("%s", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("File not opened\n");
		return 1;
	}
	while (read(fd, &ch, 1)) {
		++chars;

		if (ch == '\n')
			++lines;

		if (ch == ' ' || ch == '\t' || ch == '\n') {
			flag = 0;
		} else if (flag == 0) {// out of a word (it read a word)
			flag = 1;
			++words;
		}
	}
	if (ch != '\n' && ch)
		++lines;

	printf("%d %d %d %s\n", lines, words, chars, filename);
	close(fd);
	return 0;
}
