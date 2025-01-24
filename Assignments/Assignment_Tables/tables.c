#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZESUB 64
#define	SIZEMARKS 1024
#define	SIZE 512

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
	int *point;
}mark;

enum Commands {GRADE, CGPA, SGPA, FAILED, TOPSEM, TOPSUB, TOPNSUB, STDEV, EXIT};

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
double find_cgpa(mark *marks, subject subjects[], int sub_len, int marks_len, long mis);
double find_sgpa(mark *marks, subject subjects[], long mis, int marks_len, int sub_len, int semester);
void print_failed(mark *marks, grade grades[], subject subjects[], long mis, int marks_len, int sub_len);
int credits(subject subjects[], int sub_len, int semester);

int interpret_cmd(char cmd[]) {
	if (strcmp(cmd, "grade") == 0) return GRADE;
	if (strcmp(cmd, "cgpa") == 0) return CGPA;
	if (strcmp(cmd, "sgpa") == 0) return SGPA;
	if (strcmp(cmd, "exit") == 0) return EXIT;
	if (strcmp(cmd, "failed") == 0) return FAILED;
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

int read_subjects(char *filename, subject subjects[]) {
	int fd, i = 0;
	char line[1024];

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - subjects.csv\n");
		exit(1);
	}
	while (readline(fd, line)) {
		/* cut the line into "tokens" separated
		* on ","
		* and store each in subjects[i].... 
		*/
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
	int fd, i = 0;
	char line[SIZE];

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		printf("can't open file - grades.csv\n");
		exit(1);
	}
	while (i < sub_len) {
		readline(fd, line);
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
    int fd, i;
    char line[SIZE];
    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("can't open file - grades.csv\n");
        exit(1);
    }
    while (readline(fd, line)) {
        // Allocate memory for sub_marks and point arrays
        marks[i].sub_marks = (double *)malloc(sub_len * sizeof(double));
        marks[i].point = (int *)malloc(sub_len * sizeof(int));

        if (marks[i].sub_marks == NULL || marks[i].point == NULL) {
            printf("Memory allocation failed for student %d\n", i);
            exit(1);
        }

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
		case 0 :
			printf("FF");
			break;
		case 4 :
			printf("DD");
			break;
		case 5 :
			printf("CD");
			break;
		case 6 :
			printf("CC");
			break;
		case 7 :
			printf("BC");
			break;
		case 8 :
			printf("BB");
			break;
		case 9 :
			printf("AB");
			break;
		case 10 :
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
			if (q) printf(", ");
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
	if (mis_ind == -1 || sub_ind == -1) printf("----------invalid input------------\n");
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
		if (sgpa == -1) break;
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
		if (marks[found_mis].point[i] == 0) printf("%s ", subjects[i].sub_name);
	}
	printf("\n");
}
//**********************************************//
int subject_index(subject subjects[], char *subject, int sub_len) {
	for (int i = 0; i < sub_len; i++) {
		if (strcmp(subjects[i].sub_name, subject) == 0) {
			return i;
		}
	}
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
		if (subjects[i].semester == semester) sum += subjects[i].credits;
	}
	return sum;
}
//**********************************************//

int main()
{
	int sub_len, marks_len, grade_len, semester;
	long misid;
	float cgpa, sgpa;

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
			case GRADE :
				scanf("%s", data1);
				//printf("parsed data1: '%s'\n", data1);
				if (strcmp(data1, "all") != 0) {
					scanf("%s", data2);
					long mis = atol(data1);
					print_student_mis_grade(marks, subjects, mis, data2, marks_len, sub_len);
				} else {
					printf("Executing GRADE_ALL...\n");
					print_grade_all(marks, marks_len, sub_len);
				}
				break;
			case CGPA :
				scanf("%s", data1);
				misid = atol(data1);
				cgpa = find_cgpa(marks, subjects, sub_len, marks_len, misid);
				if (cgpa >= 0) printf("%.2f\n", cgpa);
				break;
			case SGPA :
				scanf("%s", data1);
				misid = atol(data1);
				scanf("%s", data2);
				semester = atoi(data2);
				sgpa = find_sgpa(marks, subjects, misid, marks_len, sub_len, semester);
				if (sgpa >= 0) printf("%.2f\n", sgpa);
				break;
			case FAILED :
				scanf("%s", data1);
				misid = atol(data1);
				print_failed(marks, grades, subjects, misid, marks_len, sub_len);
				break;
			case EXIT :
				for (int i = 0; i < marks_len; i++)
					free(marks[i].sub_marks);
				return 0;
			default :
				printf("invalid command\n");
		}
	}

	for (int i = 0; i < marks_len; i++) {
		free(marks[i].sub_marks);
	}
	return 0;
}
