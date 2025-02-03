#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
typedef struct transaction {
	double amount;
	time_t time;
	unsigned int from_id;
	unsigned int to_id;
	char location[32];
} transaction;
//print time("DD:MM:YYYY HH:MM:SS format")of transaction with lowest amount
int lowest(transaction transactions[], int len)
{
	int min_index = 0, i;

	for (i = 1; i < len; i++) {
		if (transactions[i].amount < transactions[min_index].amount)
			min_index = i;
	}
	return min_index;
}

int main()
{
	int fd, len, j, min_index;
	char filename[128];

	len = 0;
    scanf("%s", filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("Open Failed\n");
		return 1;
	}

	read(fd, &len, sizeof(int));
	transaction transactions[len];

	for (j = 0; j < len; j++)
		read(fd, &transactions[j], sizeof(transaction));
	min_index = lowest(transactions, len);

    struct tm *time;
	char file_time[128];

    time = gmtime(&transactions[min_index].time);
    strftime(file_time, 128, "%d:%m:%Y %H:%M:%S", time);// Y-fullyr(4dig), y-last2dig, H-24hr-frmt
    printf("%s\n", file_time);
    close(fd);
    return 0;
}
