#include <stdio.h>
#include <string.h>
struct course {
	char name[32];
	char course_id[16];
	int credits;
	int type; //type=1 is theory course,2 is lab course&3 is tutorial course
	char category[16];
};

int main()
{
	int i, sum_all, sum_lab, sum_theory, num_courses, sum[8] = {0}, valid;

	i = 0;
	valid = 0;
	sum_all = 0;
	sum_lab = 0;
	sum_theory = 0;
	num_courses = 0;

	struct course course[128];
	char *categories[6] = {"PCC", "HSSC", "LC", "LLC", "OE", "DE"};

	while (scanf("%s %s %d %d %s",
		     course[num_courses].name,
		     course[num_courses].course_id,
		     &course[num_courses].credits,
		     &course[num_courses].type,
		     course[num_courses].category) == 5) {
		if (course[num_courses].type < 1 || course[num_courses].type > 3) {
			printf("invalid type\n");
			break;
		}
		valid = 0;
		for (int k = 0; k < 6; k++) {
		    if (strcmp(course[num_courses].category, categories[k]) == 0) {
		        valid = 1;
		        break;
	    	}
		}
		if (valid != 1) {
		    printf("invalid category\n");
		    break;
		}
		sum_all += course[num_courses].credits;

		if (course[num_courses].type == 2)
			sum_lab += course[num_courses].credits;
		if (course[num_courses].type == 1)
			sum_theory += course[num_courses].credits;

		for (int j = 0; j < 6; j++) {
			int x;

			x = strcmp(categories[j], course[num_courses].category);
			if (x == 0) {
				sum[j] = sum[j] + course[num_courses].credits;
				break;
			}
		}
		num_courses++;
	}

	//Print(a)Sum of credits of all courses(b)-"-credits of all lab courses
	printf("%d\n%d\n", sum_all, sum_lab);
	//Print : (c) sum of credits for all theory courses, category wise
	// edge case : if input contains 2 same categories

	for (i = 0; i < num_courses; i++) {
		if (sum[i] > 0)
			printf("%s %d\n", course[i].category, sum[i]);
	}
	return 0;
}
