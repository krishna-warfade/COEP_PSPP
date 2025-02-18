/*
Given three CSV files, named as
subjects.csv

    containing entries in this format:
subject-name, no-of-credits, semester
    For example, an entry like
        dsgt, 3, 2
    means, that subject dsgt has 3 credits and is offered in 2nd semester.

    Lets say this file has 'N' entries

grades.csv  containint 'N' entries specifiying the grade ranges of marks of students in each subject,
            in the same order as they appear in subjects.csv
            each row contains 6 nos, they are upper bounds on the marks for a grade (starting with grade point 4)
            Consider the lower bound for lowest(first) grade is 0,
            and upper bound for last grade is 100.
            Entries can be real numbers

            So an entry like this
            36,51,54,59,60,77, 88
            means
            FF grade(0 pts) range is 0-36.00
            DD grade(4 pts) range is 36.01-51.00
            CD grade(5 pts) range is 51.01-54.00
            CC grade(6 pts) range is 54.01-59.00
            BC grade(7 pts) range is 59.01-60.00
            BB grade(8 pts) range is 60.01-77.00
            AB grade(9 pts) range is 77.01-88.00
            AA grade(10 pts) range is 88.01-100.00
marks.csv
    List of students, with their marks in the 'N' subjects in that order.

Write a program that

    reads the data from these 3 files, assuming they are in the CWD
    displays a prompt (that looks like this: ">") and then accepts a particular query and answers it. The queries are explained below

   grade <mis> <subject-name>
        e.g.
       grade 11122312  os
        Give the grade of the student specified by MIS id in <mis> for the subject in <subject-name>


   grade all
        Print the list of all students with grades in each subject, in CSV format
        e.g. output will look like this
        111212121, AA, BB, CC, DD, FF, AB, BC, BB, AB, AB
        111212321, AB, BC, BC, CD, BB, AB, BC, BB, AB, BC
        111211121, AB, BC, CD, DD, AB, BB, CC, BC, AB, AB


    cgpa <mis>
        e.g.
        cgpa 11232132
        Calculates and prints the CGPA of a student


    sgpa  <MIS>  <sem>
        e.g.
   sgpa  1101010101 3
        Calculates and prints the SGPA of a student in a given semester


   failed  <mis>
        Lists all subject names in which the student given by <mis> has failed

  topsem  <sem>
  Eg.
  topsem 3
  Lists the topmost student, in each subject, in semester 3, in this format:
  112312321, pspp
  123123123, os
  123212321, dsa

  topsub  <subject>
  Eg.
  topsub dsa
  Lists the topper student MIS ID, in given subject,
  112312321

  topnsub  <sub> <n>
  Eg.
  topnsub pspp 5
  Lists the topmost 5 students, in pspp subject, with marks in ascending order
  112312321, 11.11
  123123123, 123.23
  123212321, 123.45

   failed  <mis>
        Lists all subject names in which the student given by <mis> has failed

   stdev  <subject>
       prints the standard deviation of marks in the given subject, as a floating point upto 2 decimals

  exit
       stop the program
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#define SIZESUB 64
#define	SIZEMARKS 1024
#define	SIZE 512
typedef struct subject{
	char sub_name[64];
	int credits;
	int semester;
} subject;
typedef struct grade{
	double range[7];
} grade;
typedef struct mark{
	long misid;
	double *sub_marks;
	int *point;
} mark;
enum commands {GRADE, CGPA, SGPA, FAILED, TOPSEM, TOPSUB, TOPNSUB, STDEV, EXIT};
int interpret_cmd(char *cmd);
void insert_sub(char *line, subject subjects[], int i);
void insert_grade(char *line, grade grades[], int i);
void insert_mark(char *line, mark *marks, int i, int sub_len);
int readline(int fd, char *s);
int read_subjects(char *filename, subject subjects[]);
int read_grades(char *filename, grade grades[], int sub_len);
int read_marks(char *filename, mark *marks, int sub_len);
void print_grade_all(mark *marks, int i, int j);
void print_grade_student(grade grades[], subject subjects[], mark *marks, int marks_len, int sub_len, long data1, char *data2);
int subject_index(subject subjects[], char *subject, int sub_len);
int mis_index(mark *marks, long misid, int len);
int check_sem(subject subjects[], int sub_len, int sem);
double find_cgpa(mark *marks, subject subjects[], int sub_len, int marks_len, long mis);
double find_sgpa(mark *marks, subject subjects[], long mis, int marks_len, int sub_len, int semester);
void print_failed(mark *marks, grade grades[], subject subjects[], long mis, int marks_len, int sub_len);
int credits(subject subjects[], int sub_len, int semester);
float mean(mark *marks, int sub_len, int sub_ind);
float rms(mark *marks, int sub_len, int sub_ind);
float stdev(mark *marks, subject subjects[], char *subject, int marks_len, int sub_len);
void find_topsem(mark *marks, subject subjects[], int sem, int marks_len, int sub_len);
int find_topsub(mark *marks, subject subjects[], char *subject, int marks_len, int sub_len);
void find_topnsub(mark *marks, subject subjects[], char *subject, int no_of_subj, int marks_len, int sub_len);
int interpret_cmd(char cmd[])
{
	if (strcmp(cmd, "grade") == 0)
		return GRADE;
	if (strcmp(cmd, "cgpa") == 0)
		return CGPA;
	if (strcmp(cmd, "sgpa") == 0)
		return SGPA;
	if (strcmp(cmd, "failed") == 0)
		return FAILED;
	if (strcmp(cmd, "stdev") == 0)
		return STDEV;
	if (strcmp(cmd, "topsem") == 0)
		return TOPSEM;
	if (strcmp(cmd, "topsub") == 0)
		return TOPSUB;
	if (strcmp(cmd, "topnsub") == 0)
		return TOPNSUB;
	if (strcmp(cmd, "exit") == 0)
		return EXIT;
	return -1;
}
int readline(int fd, char *s)
{
	char *p = s;
	while (((s - p) < SIZE - 1) && (read(fd, s, 1) == 1) && (*s != '\n'))
		s++;
	*s = '\0';
	return (s - p);
}
//**********************************************//
void insert_sub(char line[], subject subjects[], int i)
{
	char *token;

	token = strtok(line, ",");

	if (token != NULL)
		strcpy(subjects[i].sub_name, token);

	token = strtok(NULL, ",");
	if (token != NULL)
		subjects[i].credits = atoi(token);
	token = strtok(NULL, ",");
	if (token != NULL)
		subjects[i].semester = atoi(token);
}
int read_subjects(char *filename, subject subjects[])
{
	int fd, i = 0, j;
	char line[1024];

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - subjects.csv\n");
		exit(1);
	}
	while (j = readline(fd, line)) {
		if (j == 0)
			continue;
		insert_sub(line, subjects, i);
		i++;
	}
	close(fd);
	return i;
}
//**********************************************//
void insert_grade(char line[], grade grades[], int i)
{
	char *token;
	int j = 0;

	token = strtok(line, ",");
	grades[i].range[j] = atof(token);
	j++;
	while (token != NULL && j < 7) {
		token = strtok(NULL, ",");
		grades[i].range[j] = atof(token);
		j++;
	}
}
int read_grades(char *filename, grade grades[], int sub_len)
{
	int fd, i = 0, j;
	char line[SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - grades.csv\n");
		exit(1);
	}
	while (i < sub_len) {
		j = readline(fd, line);
		if (j == 0)
			continue;
		insert_grade(line, grades, i);
		i++;
	}
	close(fd);
	return i;
}
//**********************************************//
void insert_mark(char line[], mark *marks, int i, int sub_len)
{
	char *token;
	int j = 0;

	token = strtok(line, ",");
	if (token != NULL)
		marks[i].misid = atol(token);
	while (token != NULL && j < sub_len) {
		token = strtok(NULL, ",");
		if (token != NULL) {
			marks[i].sub_marks[j] = atof(token);
			j++;
		}
	}
}
int read_marks(char *filename, mark *marks, int sub_len)
{
	int fd, i, j;
	char line[SIZE];

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - grades.csv\n");
		exit(1);
	}
	while (j = readline(fd, line)) {
		//allocate memory for sub_marks and point arrays
		if (j == 0)
			continue;
		marks[i].sub_marks = (double *)malloc(sub_len * sizeof(double));
		marks[i].point = (int *)malloc(sub_len * sizeof(int));
		insert_mark(line, marks, i, sub_len);
		i++;
	}
	close(fd);
	return i;
}
//**********************************************//
int find_point(double sub_marks, grade grades[], int i)
{
	if (sub_marks <= grades[i].range[0]) {
		return 0;
	} else if (sub_marks <= grades[i].range[1]) {
		return 4;
	} else if (sub_marks <= grades[i].range[2]) {
		return 5;
	} else if (sub_marks <= grades[i].range[3]) {
		return 6;
	} else if (sub_marks <= grades[i].range[4]) {
		return 7;
	} else if (sub_marks <= grades[i].range[5]) {
		return 8;
	} else if (sub_marks <= grades[i].range[6]) {
		return 9;
	} else {
		return 10;
	}
}
void assign_points(mark *marks, grade grades[], int sub_len, int marks_len)
{
	int i, j;

	for (i = 0; i < marks_len; i++) {
		for (j = 0; j < sub_len; j++) {
			marks[i].point[j] = find_point(marks[i].sub_marks[j], grades, j);
		}
	}
}
void assign_grades(mark *marks, int j, int k)
{
	switch (marks[j].point[k]) {
	case 0:
		printf("FF");
		break;
	case 4:
		printf("DD");
		break;
	case 5:
		printf("CD");
		break;
	case 6:
		printf("CC");
		break;
	case 7:
		printf("BC");
		break;
	case 8:
		printf("BB");
		break;
	case 9:
		printf("AB");
		break;
	case 10:
		printf("AA");
		break;
	}
}
//**********************************************//
void print_grade_all(mark *marks, int i, int j)
{
	int p, q;

	for (p = 0; p < i; p++) {
		printf("%ld, ", marks[p].misid);
		for (q = 0; q < j; q++) {
			if (q)
				printf(", ");
			assign_grades(marks, p, q);
		}
		printf("\n");
	}
}
void print_student_mis_grade(mark *marks, subject subjects[], long mis, char *data2, int marks_len, int sub_len)
{
	int mis_ind, sub_ind;

	mis_ind = mis_index(marks, mis, marks_len);
	sub_ind = subject_index(subjects, data2, sub_len);
	assign_grades(marks, mis_ind, sub_ind);
	if (mis_ind == -1 || sub_ind == -1)
		printf("invalid input\n");
	printf("\n");
}
//**********************************************//
double find_sgpa(mark *marks, subject subjects[], long mis, int marks_len, int sub_len, int semester)
{
	int found_mis, total_cred = 0;

	float sum = 0, sgpa = 0.0;

	found_mis = mis_index(marks, mis, marks_len);
	if (found_mis == -1) {
		printf("invalid mis\n");
		return found_mis;
	}
	for (int i = 0; i < sub_len; i++) {
		if (subjects[i].semester == semester) {
			total_cred += subjects[i].credits;
			sum += subjects[i].credits * marks[found_mis].point[i];
		}
	}
	sgpa = (float)(sum / total_cred);
	return sgpa;
}
double find_cgpa(mark *marks, subject subjects[], int sub_len, int marks_len, long mis)
{
	int totalCredits = 0, credit;
	double sum = 0.0, sgpa, cgpa = 0.0;

	for (int i = 1; i < 8; i++) {
		credit = credits(subjects, sub_len, i);//i is the semester which is updated in every iteration
		sgpa = find_sgpa(marks, subjects, mis, marks_len, sub_len, i);
		if (sgpa == -1)
			break;
		sum += (credit * sgpa);
		totalCredits += credit;
	}
	cgpa = (float)(sum / totalCredits);
	return cgpa;
}
//**********************************************//
void print_failed(mark *marks, grade grades[], subject subjects[], long mis, int marks_len, int sub_len)//failed means FF = 0 points
{
	int found_mis, i;

	found_mis = mis_index(marks, mis, marks_len);
	if (found_mis == -1) {
		printf("invalid mis\n");
		return;
	}
	for (i = 0; i < sub_len; i++) {
		if (marks[found_mis].point[i] == 0)
			printf("%s ", subjects[i].sub_name);
	}
	printf("\n");
}
//**********************************************//
float mean(mark *marks, int marks_len, int sub_ind)
{
	float avg, sum = 0.00;

	for (int i = 0; i < marks_len; i++)
		sum += marks[i].sub_marks[sub_ind];
	avg = sum / marks_len;
	return avg;
}
float rms(mark *marks, int marks_len, int sub_ind)
{
	float rms, sum = 0.00;

	for (int i = 0; i < marks_len; i++)
		sum += marks[i].sub_marks[sub_ind] * marks[i].sub_marks[sub_ind];
	rms = sum / marks_len;
	return rms;
}
float stdev(mark *marks, subject subjects[], char *sub, int marks_len, int sub_len)
{
	float stdev = 0.00, mean_value = 0.00, rms_value = 0.00;
	int sub_ind;

	sub_ind = subject_index(subjects, sub, sub_len);
	if (sub_ind == -1)
		printf("invalid subject\n");
	rms_value = rms(marks, marks_len, sub_ind);
	mean_value = mean(marks, marks_len, sub_ind);
	stdev = sqrt(rms_value - mean_value * mean_value);
	return stdev;
}
//**********************************************//
int subject_index(subject subjects[], char *subject, int sub_len)
{
	for (int i = 0; i < sub_len; i++)
		if (strcmp(subjects[i].sub_name, subject) == 0)
			return i;
	return -1;
}
int mis_index(mark *marks, long misid, int len)
{
	int i;

	for (i = 0; i < len; i++) {
		if (marks[i].misid == misid)
			return i;
	}
	return -1;
}
int credits(subject subjects[], int sub_len, int semester)
{
	int i, sum = 0;

	for (i = 0; i < sub_len; i++) {
		if (subjects[i].semester == semester)
			sum += subjects[i].credits;
	}
	return sum;
}
int check_sem(subject subjects[], int sub_len, int sem)
{
	int i;

	for (i = 0; i < sub_len; i++) {
		if (subjects[i].semester == sem)
			return 1;
	}
	return -1;
}
int find_topsub(mark *marks, subject subjects[], char *subject, int marks_len, int sub_len) //linear search
{
	int i, sub_ind, maxm;

	sub_ind = subject_index(subjects, subject, sub_len);
	if (sub_ind == -1) {
		printf("invalid subject\n");
		return -1;
	}
	maxm = 0;

	for (i = 1; i < marks_len; i++)
		if (marks[i].sub_marks[sub_ind] > marks[maxm].sub_marks[sub_ind])
			maxm = i;
	return maxm;
}
void find_topnsub(mark *marks, subject subjects[], char *subject, int no_of_subj, int marks_len, int sub_len)
{
	int i, sub_ind, index[marks_len], max_ind, j, temp, ind;

	sub_ind = subject_index(subjects, subject, sub_len);
	if (sub_ind == -1) {
		printf("invalid subject\n");
		return;
	}
	for (i = 0; i < marks_len; i++)
		index[i] = i;
	/*SELECTION SORT*/
	for (i = 0; i < marks_len; i++) {
		max_ind = i;
		for (j = i + 1; j < marks_len; j++) {
			if (marks[index[j]].sub_marks[sub_ind] > marks[index[max_ind]].sub_marks[sub_ind])
				max_ind = j;
		}
		temp = index[i];
		index[i] = index[max_ind];
		index[max_ind] = temp;
	}
	for (i = no_of_subj - 1; i >= 0; i--) {
		ind = index[i];
		printf("%ld, %.2lf\n", marks[ind].misid, marks[ind].sub_marks[sub_ind]);
	}
}
//**********************************************//
void find_topsem(mark *marks, subject subjects[], int sem, int marks_len, int sub_len)
{
	int i = 0, found_sem;

	found_sem = check_sem(subjects, sub_len, sem);
	if (found_sem == -1) {
		printf("invalid sem\n");
		return;
	}
	for (i = 0; i < sub_len; i++) {
		if (subjects[i].semester == sem)
			printf("%ld, %s\n", marks[find_topsub(marks, subjects, subjects[i].sub_name, marks_len, sub_len)].misid, subjects[i].sub_name);
	}
	return;
}
//**********************************************//
int main()
{
	int sub_len, marks_len, grade_len, semester, i, no_of_subj;
	long misid, top;
	float cgpa, sgpa, std_dev;

	subject subjects[SIZESUB];
	grade grades[1024];
	mark marks[SIZEMARKS];
	/*Reads the data from the 3 files
	*Read Subjects */
	sub_len = read_subjects("subjects.csv", subjects);
	//Read Grades
	grade_len = read_grades("grades.csv", grades, sub_len);
	//Read Marks
	marks_len = read_marks("marks.csv", marks, sub_len);

	if (grade_len != sub_len) {
		printf("no. of subjects & grades not matching\n");
		return 1;
	}
	assign_points(marks, grades, sub_len, marks_len);
	//Take queries as input in cmd

	while (1) {
		char cmd[SIZE], data1[32], data2[32];
		int retval_cmd;

		printf(">");
		scanf("%s", cmd);
		retval_cmd = interpret_cmd(cmd);

		if (retval_cmd == EXIT)
			break;

		switch (retval_cmd) {
		case GRADE:
			scanf("%s", data1);
			if (strcmp(data1, "all") != 0) {
				scanf("%s", data2);
				misid = atol(data1);
				print_student_mis_grade(marks, subjects, misid, data2, marks_len, sub_len);
			} else {
				print_grade_all(marks, marks_len, sub_len);
			}
			break;
		case CGPA:
			scanf("%s", data1);
			misid = atol(data1);
			cgpa = find_cgpa(marks, subjects, sub_len, marks_len, misid);
			if (cgpa >= 0)
				printf("%.2f\n", cgpa);
			break;
		case SGPA:
			scanf("%s", data1);
			misid = atol(data1);
			scanf("%s", data2);
			semester = atoi(data2);
			sgpa = find_sgpa(marks, subjects, misid, marks_len, sub_len, semester);
			if (sgpa >= 0)
				printf("%.2f\n", sgpa);
			break;
		case FAILED:
			scanf("%s", data1);
			misid = atol(data1);
			print_failed(marks, grades, subjects, misid, marks_len, sub_len);
			break;
		case STDEV:
			scanf("%s", data1);
			std_dev = stdev(marks, subjects, data1, marks_len, sub_len);
			if (std_dev > 0)
				printf("%.2f\n", std_dev);
			break;
		case TOPSUB:
			scanf("%s", data1);
			top = find_topsub(marks, subjects, data1, marks_len, sub_len);
			if (top != -1)
				printf("%ld\n", marks[top].misid);
			break;
		case TOPSEM:
			scanf("%s", data1);
			semester = atoi(data1);
			find_topsem(marks, subjects, semester, marks_len, sub_len);
			break;
		case TOPNSUB:
			scanf("%s", data1);//subject
			scanf("%s", data2);
			no_of_subj = atoi(data2);
			find_topnsub(marks, subjects, data1, no_of_subj, marks_len, sub_len);
			break;
		case EXIT:
			for (i = 0; i < marks_len; i++)
				free(marks[i].sub_marks);
			return 0;
		default:
			printf("invalid command\n");
		}
	}
	for (i = 0; i < marks_len; i++)
		free(marks[i].sub_marks);
	return 0;
}
