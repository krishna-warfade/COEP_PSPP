#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 256

int max_w_line(char *line)
{
	int len_line, max_word_len = 0, i, wi = 0; /*wi = index of word */
	char ch;
	char word[SIZE];

	len_line = strlen(line);

	for (i = 0; i <= len_line; i++) {
		ch = line[i];
		if (ch == '\n' || ch == ' ' || ch == '\t' || ch == '\0') {
			word[wi] = '\0';

			if (strlen(word) > max_word_len)
				max_word_len = strlen(word);
			wi = 0; /*start reading a new word */
		} else {
			word[wi] = ch;
			wi++;
		}
	}
	return max_word_len;
}

int main(int argc, char *argv[])
{
	int fd, i = 0, len_word, max = 0;
	char ch;
	char *line = (char *)malloc(SIZE * sizeof(char));
	char *reqd = NULL;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("open failed\n");
		return 1;
	}
	while (read(fd, &ch, 1)) {
		if (ch == '\n') {
			line[i] = '\0';
			len_word = max_w_line(line);
			i = 0;
			if (len_word > max) {
				max = len_word;
				free(reqd);
				reqd = line;
				line = (char *)malloc(SIZE * sizeof(char));
			}
		} else {
			line[i] = ch;
			i++;
		}
	}
	printf("%s\n", reqd);
	close(fd);
	free(reqd);
	return 0;
}
