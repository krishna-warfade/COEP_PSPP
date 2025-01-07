#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char make_lower(char ch)
{	if (ch >= 'A' && ch <= 'Z')
		return ch + 32;
 	return ch;
}

int is_pal(char const *word)
{
	int len, i;

	len = strlen(word);
	if (len == 1)
		return 1;

	for (i = 0; i < len / 2; i++) {
		if (make_lower((word[i])) != make_lower(word[len - i - 1]))
			return 0;
		else if (word[i] == ' ' || word[i] == '\n' || word[i] == '\t')
			i++;
	}
	return 1;
}

int main()
{
	int fd, i = 0;
	char data[256], ch, filename[128];

    scanf("%s", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("open failed\n");
		return 1;
	}
	while (read(fd, &ch, 1)) {
		if (ch == ' ' || ch == '\n' || ch == '\t') {
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
