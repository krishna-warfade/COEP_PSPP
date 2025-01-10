#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct subject{
	char sub_name[64];
	int credits;
	int semester;
}subject;
typedef struct grade{
	double range[7];
}grade;
typedef struct mark{
	long misid;
	double *sub_marks;
}mark;

enum Commands {GRADE_ALL, GRADE_STUDENT, EXIT, INVALID_CMD};

int interpret_cmd(char *cmd);
void insert_sub(char *line, subject subjects[], int i);
void insert_grade(char *line, grade grades[], int i);
void insert_mark(char *line, mark *marks, int i, int sub_len);
int readline(int fd, char *data, int size);
int read_subjects(char *filename, subject subjects[], int size);
int read_grades(char *filename, grade grades[], int size);
int read_marks(char *filename, mark *marks, int size, int sub_len);
void print_grade_all(grade grades[], subject subjects[], mark *marks, int marks_len, int sub_len);
void print_grade_student(grade grades[], subject subjects[], mark *marks, int marks_len, int sub_len, long data1, char *data2);
int subject_index(mark *marks,char *cmd, int i, int sub_len);

int interpret_cmd(char *cmd) {
	if (strcmp(cmd, "grade all") == 0) return GRADE_ALL;
	if (strcmp(cmd, "grade ") == 0) return GRADE_STUDENT;
	if (strcmp(cmd, "exit") == 0) return EXIT;
	return INVALID_CMD;
}

void insert_sub(char *line, subject subjects[], int i)
{
	char *token;

	token = strtok(line, ",");
	if (token != NULL) {
		strncpy(subjects[i].sub_name, token, sizeof(subjects[i].sub_name) - 1);
		subjects[i].sub_name[sizeof(subjects[i].sub_name) - 1] = '\0';
	}
	token = strtok(NULL, ",");
	if (token != NULL)
		subjects[i].credits = atoi(token);	
	token = strtok(NULL, ",");
	if (token != NULL)
		subjects[i].semester = atoi(token);
}

void insert_grade(char *line, grade grades[], int i)
{
	char *token;
	int j = 0;

	token = strtok(line, ",");
	while (token != NULL && j < 7) {
		grades[i].range[j++] = atof(token);
		token = strtok(NULL, ",");
	}
}

void insert_mark(char *line, mark *marks, int i, int sub_len)
{
	char *token;
	int j = 0;

	token = strtok(line, ",");
	if (token != NULL)
		marks[i].misid = atol(token);

	marks[i].sub_marks = (double *)malloc(sub_len * sizeof(double));
	while (token != NULL && j < sub_len) {
		token = strtok(NULL, ",");
		if (token != NULL)
			marks[i].sub_marks[j++] = atof(token);
	}
}

int readline(int fd, char *data, int size)
{
	int len = 0;
	char ch;

	while (read(fd, &ch, 1) && ch != '\n' && len < size - 1) {
		data[len] = ch;
		len++;
	}
	data[len] = '\0';
	return len;
}

int read_subjects(char *filename, subject subjects[], int size) {
	int fd, n, i;
	char data[1024];

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - subjects.csv\n");
		exit(1);
	}
	while ((n = readline(fd, data, 1024)) && i < size) {
		/* cut the line into "tokens" separated
		* on ","
		* and store each in subjects[i].... 
		*/
		insert_sub(data, subjects, i);
		i++;
	}
	close(fd);
	return i;
}

int read_grades(char *filename, grade grades[], int size)
{
	int fd, n, i;
	char data[1024];

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - grades.csv\n");
		exit(1);
	}
	while ((n = readline(fd, data, 1024)) && i < size) {
		insert_grade(data, grades, i);
		i++;
	}
	close(fd);
	return i;
}

int read_marks(char *filename, mark *marks, int size, int sub_len)
{
	int fd, n, i;
	char data[1024];

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - grades.csv\n");
		exit(1);
	}
	while ((n = readline(fd, data, 1024)) && i < size) {
		insert_mark(data, marks, i, sub_len);
		i++;
	}
	close(fd);
	return i;
}

int subject_index(subject subjects[], char *data2, int sub_len) {
	subj_name = data2;
	for (int i = 0; i < sub_len; i++) {
		if (strcmp(subjects[i].sub_name, subj_name) == 0) {
			return i;
		} else {
			printf("invalid subject");
		}
	}
	return -1;
}

void print_grade_all(grade grades[], subject subjects[], mark *marks, int marks_len, int sub_len)
{
	int i, j;

	for (i = 0; i < marks_len; i++) { //rows(marks-row for specified no of sub)
		printf("%ld", marks[i].misid); //print misid

		for(j = 0; j < sub_len; j++) { //col(marks-col for specified no of sub)
			double Marks;
			char *grd;

			Marks = marks[i].sub_marks[j];
			/*if (Marks >= 0.00 && Marks <= 36.00) {
				grd = "FF";
			} else if (Marks >= 36.01 && Marks <= 51.00) {
				grd = "DD";
			} else if (Marks >= 51.01 && Marks <= 54.00) {
				grd = "CD";
			} else if (Marks >= 54.01 && Marks <= 59.00) {
				grd = "CC";
			} else if (Marks >= 59.01 && Marks <= 60.00) {
				grd = "BC";
			} else if (Marks >= 60.01 && Marks <= 77.00) {
				grd = "BB";
			} else if (Marks >= 77.01 && Marks <= 88.00) {
				grd = "AB";
			} else if (Marks >= 88.01 && Marks <= 100.00) {
				grd = "AA";
			}*/
			printf(", %s", grd);
		}
		printf("\n");
	}
}

void print_grade_student(grade grades[], subject subjects[], mark *marks, int marks_len, int sub_len, long data1, char *data2) {
	long mis;
	char sub;
	int mis_index;

	mis = data1;
	sub = data2;
	for (int i = 0; i < marks_len; i++) {
		if (strcmp(marks[i].misid, mis) == 0) {
			mis_index = i;
		}
		for (int j = 0; j < sub_len; j++) {
			if(strcmp( , sub) == 0)
		}
	}
}

int main()
{
	int sub_len;
	int marks_len;

	subject subjects[1024];
	grade grades[1024];
	mark *marks = malloc(512 * sizeof(mark));
	/*Reads the data from the 3 files
	*Read Subjects */
	sub_len = read_subjects("subjects.csv", subjects, 1024);
	//Read Grades
	read_grades("grades.csv", grades, 1024);
	//Read Marks
	marks_len = read_marks("marks.csv", marks, 512, sub_len);

	//Take queries as input in cmd
	char cmd[512];

	while (1) {
		char ch;
		int i = 0;

		printf(">");
		while (1) {
			ch = getchar();
			if (ch == '\n') {
				cmd[i] = '\0';
				break;
			}
			if (ch == EOF) {
				for (int i = 0; i < marks_len; i++)
					free(marks[i].sub_marks);
				free(marks);
				return 0;
			}
			if (i < 511) {
				cmd[i++] = ch; //store the chars in cmd array
			} else {
				printf("too long command\n");
				while ((ch = getchar()) != '\n' && ch != -1)
				;
				i = 0;
				break;
			}
		}
		if (i == 0) continue;
		//cmd[i] = '\0'; //null-terminate cmd string

		switch (interpret_cmd(cmd)) {
			case GRADE_ALL :
				print_grade_all(grades, subjects, marks, marks_len, sub_len);
				break;
			case EXIT :
				for (int i = 0; i < marks_len; i++)
					free(marks[i].sub_marks);
				free(marks);
				return 0;
			default :
				printf("invalid command\n");
		}
	}
	for (int i = 0; i < marks_len; i++) {
		free(marks[i].sub_marks);
	}
	free(marks);
	return 0;
}

