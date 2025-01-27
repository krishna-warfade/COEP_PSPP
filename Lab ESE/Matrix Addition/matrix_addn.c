#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 16

		/*EXTRACT LINE FROM FILE*/
int readline(int fd, char *line, int size)
{
	char ch;
	int len = 0;

	while(read(fd, &ch, 1) && ch != '\n') {
		line[len] = ch;
		len++;
	}
	line[len] = '\0';
	return len;
}
		/*FIND ORDER OF MATRIX(mxn)*/
int insert_order(char *line, int *rows1, int *columns1)
{
	char *token;

	token = strtok(line, "\t");
	if (token != NULL)
		*rows1 = atoi(token);
	token = strtok(NULL, "\t");
	if (token != NULL)
		*columns1 = atoi(token);
	return 0;
}
		/*EXTRACT THE DATA FROM ROWS & COLUMNS*	*/
void insert_data(char *line, int *rows1, int *columns1, int i, int arr1[SIZE][SIZE])
{
	char *token;

	token = strtok(line, "\t");
	arr1[i][0] = atoi(token);
	for (int j = 1; j < *columns1; j++) {
		token = strtok(NULL, "\t");
		arr1[i][j] = atoi(token);
	}
}
		/*READ FILE*/
int readfile(char *filename, int *rows1, int *columns1, int arr1[SIZE][SIZE])
{
	int fd, n, i;
	char line[1024];

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("cannot open file %s\n", filename);
		exit(1);
	}
	readline(fd, line, 1024);
	insert_order(line, rows1, columns1);
	while ((n = (readline(fd, line, 1024)))) {
		insert_data(line, rows1, columns1, i, arr1);
		i++;
	}
	close(fd);
	return i;
}
		/*PRINT ARRAY*/
void print_array(int arr[SIZE][SIZE], int rows, int columns)
{
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
		/*FIND SUM OF 2 ARRAYS*/
void find_sum(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int sum[SIZE][SIZE], int rows, int columns)
{
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++)
			sum[i][j] = arr1[i][j] + arr2[i][j];
	}
}

int main(int argc, char *argv[])
{
	int rows1 = 0;
	int rows2 = 0;
	int columns1 = 0;
	int columns2 = 0;
	int arr1[SIZE][SIZE], arr2[SIZE][SIZE], sum[SIZE][SIZE];

	/*READ THE 2 FILES WHICH CONSIST OF MATRICES*/
	readfile(argv[1], &rows1, &columns1, arr1);
	readfile(argv[2], &rows2, &columns2, arr2);

	/*PRINT THE 2 MATRICES, READ FROM THE FILE*/
	print_array(arr1, rows1, columns1);
	printf("----------------------\n");
	print_array(arr2, rows2, columns2);

	/*CHECK IF ADDITION IS COMPATIBLE*/
	if (rows1 != rows2 || columns1 != columns2) {
		printf("Addition not compatible\n\n");
		return 1;
	}

	/*FUNCTION TO FIND SUM, IF ADDITION IS COMPATIBLE*/
	find_sum(arr1, arr2, sum, rows1, columns1);
	printf("----------------------\n");
	printf("SUM IS :\n");

	/*PRINT THE SUM OF 2 MATRICES*/
	print_array(sum, rows1, columns1);

	return 0;
}
