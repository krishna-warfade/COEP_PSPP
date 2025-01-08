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
	/*strncpy(file_time, ctime(),
		sizeof(file_time));

	char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
			    "Aug", "Sep", "Oct", "Nov", "Dec"};
	char month[4];
	int day, hr, min, sec, yr;
	char day_string[3];

	strncpy(day_string, &file_time[8], 2);//cpy fm 8th-10th ind(day-8to10)
	day_string[2] = '\0';
	day = atoi(day_string); // strtoint

	strncpy(month, &file_time[4], 3);
	month[3] = '\0';
	int num_month = 0;

	for (i = 0; i < 12; i++) {
		int found;

		found = strcmp(months[i], month);
		if (found == 0) {
			num_month = i + 1;//as i is fm 0-11,num_mon=i + 1 alws
			break;
		}
	}
char hour[3], minute[3], second[3];

	strncpy(hour, &file_time[11], 2);
	hour[2] = '\0';
	hr = atoi(hour);
	int new_hr;

	new_hr = hr;
//	if (hr > 12) {
//		new_hr = hr - 05;
//	}
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
	printf("%02d:%02d:%04d %02d:%02d:%02d\n", day,
	       num_month, yr, new_hr, min, sec);
	close(fd);
	return 0;
}*/
