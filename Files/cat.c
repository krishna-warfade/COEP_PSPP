#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd, i;
	char data[4];
	char ch;
	fd = open("/home/krishnawarfade/Files/intro", O_RDONLY);
	if(fd == -1) {
		printf("Open failed : %s\n", "/home/krishnawarfade/Files/intro");
		return 1;
	}
	while(read(fd, &ch, 1))
		putchar(ch);
	close(fd);
	return 0;
}
