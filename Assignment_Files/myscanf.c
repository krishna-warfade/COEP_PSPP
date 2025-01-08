#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myscanf(char *format, void *arg)
{
	char ch;
	char *p = arg;
	int i, num, sign, conv;

	i = 0;
	num = 0;
	conv = 0;
	sign = 1;
	if (*format == '%') {
		format++;

		if (*format == 'd') {
			ch = getchar();
			while ((ch == ' ' || ch == '\t' || ch == '\n'))
				ch = getchar();

			if (ch == '-') {
				sign = -1;
				ch = getchar();
			} else if (ch == '+') {
				ch = getchar();
			}
			while (ch >= '0' && ch <= '9') {
				num = num * 10 + (ch - '0');
				ch = getchar();
				i++;
			}
			
			if (i > 0) {
                *(int *)p = sign * num;
                conv++;
            } else {
                return 0;
            }
			if (ch != EOF) {
                ungetc(ch, stdin);
            }
		} else if (*format == 'u') {
			ch = getchar();

			while ((ch == ' ' || ch == '\t' || ch == '\n'))
				ch = getchar();

			if (ch == '-')
				return 0;
			if (ch == '+')
				ch = getchar();

			while (ch >= '0' && ch <= '9') {
				num = num * 10 + (ch - '0');
				ch = getchar();
				i++;
			}
			if (i > 0) {
				*(unsigned int *)p = num;
				conv++;
			} else {
				return 0;
			}
			if (ch != EOF) {
                ungetc(ch, stdin);
            }
		} else if (*format == 'c') {
			ch = getchar();
			if (ch == EOF) {
				*(char *)p = ch;
				return -1;
			}
			*(char *)p = ch;
			return 1;
		} else if (*format == 'f') {
			char num[128];
			int j = 0;

			ch = getchar();
			while (ch == ' ' || ch == '\t' || ch == '\n')
				ch = getchar();
			while (ch != EOF && (ch != ' ' && ch != '\t' && ch != '\n')) {
				num[j++] = ch;
				ch = getchar();
			}
			num[j] = '\0';
			float float_num;

			float_num = atof(num);
			if (j > 0) {
				*(float *)p = float_num;
				conv++;
			} else
				return 0;
			if (ch != EOF) {
                ungetc(ch, stdin);
            }
		} else if (*format == 'l' && *(format + 1) == 'f') {
			char num[128];
			int j = 0;

			ch = getchar();
			while (ch == ' ' || ch == '\t' || ch == '\n')
				ch = getchar();
			while (ch != EOF && (ch != ' ' && ch != '\t' && ch != '\n')) {
				num[j++] = ch;
				ch = getchar();
			}
			num[j] = '\0';

			double double_num;

			double_num = atof(num);
			if (j > 0) {
				*(double *)p = double_num;
				conv++;
			} else
				return 0;
			if (ch != EOF) {
                ungetc(ch, stdin);
            }
		} else if (*format == 's') {
			char str[1024];
			int j = 0;

			ch = getchar();
			while (ch == ' ' || ch == '\t' || ch == '\n')
				ch = getchar();

			while (ch != EOF && (ch != ' ' && ch != '\t' && ch != '\n')) {
				str[j++] = ch;
				ch = getchar();
			}
			str[j] = '\0';
			if (j > 0) {
				strcpy((char *)p, str);
				conv++;
			} else  {
				return 0;
			}
		}
	}
	return conv;
}
