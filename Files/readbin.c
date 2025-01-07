#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct transaction
{
	double amount;
	time_t time;
	unsigned int from_id;
	unsigned int to_id;
	char location[32];
} transaction;
//print location&time("DD:MM:YYYY HH:MM:SS")of transaction with lowest amount
int lowest(transaction Transactions[], int len)
{
	int min_index = 0, i;

	for (i = 1; i < len; i++) {
		if (Transactions[i].amount < Transactions[min_index].amount)
			min_index = i;
	}
	return min_index;
}
int main(int argc, char *argv[])
{
	int fd, len = 0, j, min_index, i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("Open Failed\n");
		return 1;
	}

	read(fd, &len, sizeof(int));
	transaction Transactions[len];

	for (j = 0; j < len; j++) {
		read(fd, &Transactions[j], sizeof(transaction));
	}
	min_index = lowest(Transactions, len);
	printf("%s ", Transactions[min_index].location);

	char file_time[32];

	strcpy(file_time, ctime(&Transactions[min_index].time));
	char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	char month[4];
	int day, hr, min, sec, yr;
	char dayStr[3];
	
	strncpy(dayStr, &file_time[8], 2); // copy from 8th to 10th index (day on 8,9 & 10)
	dayStr[2] = '\0';
	day = atoi(dayStr); // strtoint

	strncpy(month, &file_time[4], 3);
	month[3] = '\0';
	int num_month = 0;
	
	for (i = 0; i < 12; i++) {
		int found;

		found = strcmp(months[i], month);
		if (found == 0) {
			num_month = i + 1; // as i is from 0 to 11, num_mon = i + 1 always
			break;
		}
	}
	char hour[3], minute[3], second[3];
	
	strncpy(hour, &file_time[11], 2);
	hour[2] = '\0';
	hr = atoi(hour);

	strncpy(minute, &file_time[14], 2);
	minute[2] = '\0';
	min = atoi(minute);

	strncpy(second, &file_time[17], 2);
	second[2] = '\0';
	sec = atoi(second);
	char year[5];
	strncpy(year, &file_time[20], 4);
	year[4] = '\0';
	yr = atoi(year);
	
	// print in DD:MM:YYYY HH:MM:SS format
	printf("%02d/%02d/%04d %02d:%02d:%02d\n", day, num_month, yr, hr, min, sec);
	close(fd);
	return 0;
}
