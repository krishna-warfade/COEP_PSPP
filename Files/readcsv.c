#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
typedef struct account {
	char name[16];
	unsigned long phone;
	unsigned int accid;
	double amount;	
}account;

void print_records(account a[], int len) {
	int i;
	printf("-------------\n");
	for(i = 0; i < len; i++)
		printf("%s %lu %u %.2lf\n", a[i].name,
			a[i].phone, a[i].accid, a[i].amount);
}
/* searches for a record matching 'mis' in the array
 * a[], upto length = len
 * returns the index of the first record found
 * returns -1 if not found
 */
int findmin(account a[], int i, int len) {
	double min = a[i].amount;
	int minindex = i;
	int j;
	for(j = i + 1; j < len; j++) 
		if(a[j].amount < min) {
			min = a[j].amount;
			minindex = j;
		}
	return minindex;
}
void selsort(account a[], int len) {
	account t;	
	int i, min;
	i = 0;
	while(i < len - 1) {
		//find the minimum between i and len -1
		min = findmin(a, i, len);
		//move ith minimum to ith position;
		t = a[i];
		a[i] = a[min];
		a[min] = t;
		i++;
	}
}
int readline(int fd, char *line, int size){
	/* char *p = s;
	while(((s - p) < size - 1) && (read(fd, s, 1)==1) && (*s != '\n')) 
		s++;
	*s = '\0';
	return (s - p); */
	char ch;
	int len = 0;
	while(read(fd, &ch, 1) && ch != '\n') {
		line[len] = ch;
		len++;
	}
	line[len] = '\0';
	return len;
}
void insert(char *line, account accounts[], int i) {
	/*char *p, *t;
	char token[32];
	p = line;
	t = token;

	while(*p && *p != ',') {
		*t = *p;
		p++;
		t++;
	}
	*t = '\0';
	strcpy(accounts[i].name, token);

	p++;
	t = token;
 	while(*p && *p != ',') {
		*t = *p;
		p++;
		t++;
	}
	*t = '\0';
	accounts[i].phone= atol(token);

	p++;
	t = token;
 	while(*p && *p != ',') {
		*t = *p;
		p++;
		t++;
	}
	*t = '\0';
	accounts[i].accid = atoi(token);

	p++;
	t = token;
 	while(*p && *p != ',') {
		*t = *p;
		p++;
		t++;
	}
	*t = '\0';
	accounts[i].amount = atof(token); */
	char *token;
	
	token = strtok(line, ",");
	if(token != NULL) {
		strcpy(accounts[i].name, token);
		accounts[i].name[sizeof(accounts[i].name) - 1] = '\0';
	}
	
	token = strtok(NULL, ",");
	if(token != NULL)
		accounts[i].phone = atol(token);
		
	token = strtok(NULL, ",");
	if(token != NULL)
		accounts[i].accid = atoi(token);
		
	token = strtok(NULL, ",");
	if(token != NULL)
		accounts[i].amount = atof(token);
}
int readfile(char *filename, account accounts[], int size) {
	int fd;
	char line[1024];
	int i = 0, n;
	fd = open(filename, O_RDONLY);
	if(fd == -1) {
		printf("can't open file\n");
		exit(1);
	}
	/* read the file, line by line, and insert 
	 * data into the array called accounts[]
	 */
	while((n = readline(fd, line, 1024))) {
		/* cut the line into "tokens" separated
	 	 * on ","
		 * and store each in accounts[i].... 
		 */
		insert(line, accounts, i);
		i++;
		
	}
	return i;
}
int main(int argc, char *argv[]) {
	account accounts[32];
	int len;

	/* read the file into the array of structures */
	len = readfile(argv[1], accounts, 32);
	/* sort the array of structures  */
	selsort(accounts, len);
	/* print the array of structures */
	print_records(accounts, len);
	return 0;	
}
