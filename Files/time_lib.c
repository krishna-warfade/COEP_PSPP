/*
#include <stdio.h>
#include <time.h>

int main()
{
	time_t current_time = time(NULL);
	char *now = ctime(&current_time);  // ctime returns a char* (string)
    // Printing the current date and time
	printf("%s", now);
    
    return 0;
}
*/
//"DD:MM:YYYY HH:MM:SS"

#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t current_time = time(NULL);

    // Get the current year, month, day, hour, minute, second manually
    int year = 1900 + localtime(&current_time)->tm_year;  // tm_year is years since 1900
    int month = localtime(&current_time)->tm_mon + 1;  // tm_mon is 0-11, so add 1 for actual month
    int day = localtime(&current_time)->tm_mday;
    int hour = localtime(&current_time)->tm_hour;
    int minute = localtime(&current_time)->tm_min;
    int second = localtime(&current_time)->tm_sec;

    // Format the date and time as "DD:MM:YYYY HH:MM:SS"
    printf("%02d:%02d:%04d %02d:%02d:%02d\n", day, month, year, hour, minute, second);
    
    return 0;
}

