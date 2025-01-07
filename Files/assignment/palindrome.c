#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int is_pal(char const *word)
{
	int len, i;

	len = strlen(word);
	if (len == 1)
		return 1;

	for (i = 0; i < len / 2; i++) {
		if (word[i] != word[len - i - 1])
			return 0;
		else if (word[i] == ' ' || word[i] == '\n' || word[i] == '\t')
			i++;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int fd, i = 0;
	char data[128], ch;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("open failed\n");
		return 1;
	}
	while (read(fd, &ch, 1)) {
		if (ch == '\n' || ch == ' ' || ch == '\t' || ch == ',') {
			data[i] = '\0'; // null terminating prev. word
			if (is_pal(data))
				printf("%s\n", data);
			i = 0; // for new word
		} else {
			data[i] = ch;
			i++;
		}
	}
	close(fd);
	return 0;
}
