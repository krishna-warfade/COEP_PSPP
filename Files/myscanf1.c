#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myscanf(char *format, void *arg)
{
	char ch;
	char *p = arg;
	int i , num, sign, conv;
	
	i = num = conv = 0;
	sign = 1;
	if(*format == '%') {
		format++;
		
		if(*format == 'd') {
			ch = getchar();
			while((ch == ' ' || ch == '\t' || ch == '\n'))
				ch = getchar();
			
			if(ch == '-') {
				sign = -1;
				ch = getchar();
			}
			else if(ch == '+')
				ch = getchar();
			
	        	while(ch >= '0' && ch <= '9') {
				num = num * 10 + (ch - '0');
				ch = getchar();
				i++;
			}
			if(ch == EOF) {
				*(int *)p = num;
				return -1;
			}
			else if(num) {
				*(int *)p = sign * num;
				conv++;
			}
			else
				return 0;
		}
		else if(*format == 'u') {
			ch = getchar();
			
			while((ch == ' ' || ch == '\t' || ch == '\n'))
				ch = getchar();
			
			if(ch == '-')
				return 0;
			if(ch == '+')
				ch = getchar();
				
			while(ch >= '0' && ch <= '9') {
				num = num * 10 + (ch - '0');
				ch = getchar();
				i++;
			}
			if(ch == EOF) {
				*(unsigned int *)p = num;
				return -1;
			}
			else if(num) {
				*(unsigned int *)p = (unsigned int)num;
				conv++;
			} else
				return 0;
		}
		else if(*format == 'c') {
			ch = getchar();
			if(ch == EOF) {
				*(char *)p = ch;
				return -1;
			}
			*(char *)p = ch;
				return 1;
		}
		else if(*format == 'f') {
			char num[128];
			int j = 0;
			
			ch = getchar();
			while(ch == ' ' || ch == '\t' || ch == '\n')
				ch = getchar();
			while(ch != EOF && (ch != ' ' && ch != '\t' && ch != '\n')) {
				num[j++] = ch;
				ch = getchar();
			}
			num[j] = '\0';
			float float_num;
			float_num = atof(num);
			if(ch == EOF) {
				*(float *)p = float_num;
				return -1;
			}
			else if(float_num) {
				*(float *)p = float_num;
				conv++;
			}
			else
				return 0;
		}
		else if(*format == 'l' && *(format + 1) == 'f') {
			char num[128];
			int j = 0;
			
			ch = getchar();
			while(ch == ' ' || ch == '\t' || ch == '\n')
				ch = getchar();
			while(ch != EOF && (ch != ' ' && ch != '\t' && ch != '\n')) {
				num[j++] = ch;
				ch = getchar();
			}
			num[j] = '\0';
			
			double double_num;
			double_num = atof(num);
			if(ch == EOF) {
				*(double *)p = double_num;
				return -1;
			}
			else if(double_num) {
				*(double *)p = double_num;
				conv++;
			}
			else
				return 0;
		}
		else if(*format == 's') {
			char str[1024];
			int j = 0;
			
			ch = getchar();
			while(ch == ' ' || ch == '\t' || ch == '\n')
				ch = getchar();
			
			while(ch != EOF && (ch != ' ' && ch != '\t' && ch != '\n')) {
				str[j++] = ch;
				ch = getchar();
			}
			str[j] = '\0';
			if(ch == EOF)
				return -1;
			else {
				strcpy((char *)p, str);
				conv++;
			}
		}
     }
     return conv;
}
