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
	struct course course[128];
	char *categories[6] = {"PCC", "HSSC", "LC", "LLC", "OE", "DE"};
	int i, sum_all, sum_lab, sum_theory, num_courses, sum[8], valid;

	i = 0;
	valid = 0;
	sum_all = 0;
	sum_lab = 0;
	sum_theory = 0;
	sum_credits[8] = {0};
	num_courses = 0;

	while (scanf("%s %s %d %d %s",
		     course[num_courses].name,
		     course[num_courses].course_id,
		     &course[num_courses].credits,
		     &course[num_courses].type,
		     course[num_courses].category) == 5) {
			valid = 0;
		for (int j = 0; j < 6; j++) {
			if (strcmp(categories[j], course[num_courses].category) == 0) {
				sum_credits[j] += course[num_courses].credits;
				valid = 1;
				break;
			}
		}
			
		if (valid != 1) {
		    printf("invalid category\n");
		    return 1;
		}
		sum_all += course[num_courses].credits;

		if (course[num_courses].type == 2) {
			sum_lab += course[num_courses].credits;
		} else if (course[num_courses].type == 1) {
			sum_theory += course[num_courses].credits;
		}
		num_courses++;
	}

	//Print(a)Sum of credits of all courses(b)-"-credits of all lab courses
	printf("%d\n", sum_all);
	printf("%d\n", sum_lab);
	//Print : (c) sum of credits for all theory courses, category wise
	// edge case : if input contains 2 same categories

	for (i = 0; i < 6; i++) {
		if (sum_credits[i] > 0)
			printf("%s %d\n", course[i].category, sum_credits[i]);
	}
	return 0;
}
