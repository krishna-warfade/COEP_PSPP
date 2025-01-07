#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int myscanf(char *format, void *arg) {
    char ch;
    int total_conversions = 0;

    while (*format) {
        // Skip whitespace characters in the format string
        if (*format == ' ' || *format == '\t' || *format == '\n') {
            format++;
            continue;
        }

        // If the current character in the format string is '%', handle the specifier
        if (*format == '%') {
            format++;  // Move past '%'

            // Handle integer parsing (%d)
            if (*format == 'd') {
                int num = 0;
                int sign = 1;
                ch = getchar();

                // Skip leading whitespace
                while (ch == ' ' || ch == '\t' || ch == '\n') {
                    ch = getchar();
                }

                // Handle optional sign
                if (ch == '-') {
                    sign = -1;
                    ch = getchar();
                } else if (ch == '+') {
                    ch = getchar();
                }

                // Parse digits
                while (ch >= '0' && ch <= '9') {
                    num = num * 10 + (ch - '0');
                    ch = getchar();
                }

                if (num || ch == '+' || ch == '-' || ch == '0') {
                    *(int *)arg = sign * num;
                    total_conversions++;
                } else {
                    break;
                }
            }
            // Handle unsigned integer parsing (%u)
            else if (*format == 'u') {
                unsigned int num = 0;
                ch = getchar();

                // Skip leading whitespace
                while (ch == ' ' || ch == '\t' || ch == '\n') {
                    ch = getchar();
                }

                // Handle optional sign (unsigned integers cannot have a sign)
                if(ch == '+')
                    ch = getchar();
                else if (ch == '-') {
                    return 1;  // Unsigned integers cannot have a sign
                }

                // Parse digits
                while (ch >= '0' && ch <= '9') {
                    num = num * 10 + (ch - '0');
                    ch = getchar();
                }

                if (num) {
                    *(unsigned int *)arg = num;
                    total_conversions++;
                } else {
                    break;
                }
            }
            // Handle float parsing (%f)
            else if (*format == 'f') {
                char num_str[128];
                int j = 0;

                ch = getchar();
                // Skip leading whitespace
                while (ch == ' ' || ch == '\t' || ch == '\n') {
                    ch = getchar();
                }

                // Read the number as a string
                while (ch != EOF && ch != ' ' && ch != '\t' && ch != '\n' && j < sizeof(num_str) - 1) {
                    num_str[j++] = ch;
                    ch = getchar();
                }
                num_str[j] = '\0';

                // Convert string to float manually (since we avoid atof)
                float num = 0.0f;
                int dot_seen = 0;
                int factor = 1;

                for (int k = 0; num_str[k] != '\0'; k++) {
                    if (num_str[k] == '.') {
                        dot_seen = 1;
                    } else if (num_str[k] >= '0' && num_str[k] <= '9') {
                        num = num * 10 + (num_str[k] - '0');
                        if (dot_seen) {
                            factor *= 10;
                        }
                    }
                }

                *(float *)arg = num / factor;
                total_conversions++;
            }
            // Handle double parsing (%lf)
            else if (*format == 'l' && *(format + 1) == 'f') {
                char num_str[128];
                int j = 0;

                ch = getchar();
                // Skip leading whitespace
                while (ch == ' ' || ch == '\t' || ch == '\n') {
                    ch = getchar();
                }

                // Read the number as a string
                while (ch != EOF && ch != ' ' && ch != '\t' && ch != '\n' && j < sizeof(num_str) - 1) {
                    num_str[j++] = ch;
                    ch = getchar();
                }
                num_str[j] = '\0';

                // Convert string to double manually (since we avoid atof)
                double num = 0.0;
                int dot_seen = 0;
                int factor = 1;

                for (int k = 0; num_str[k] != '\0'; k++) {
                    if (num_str[k] == '.') {
                        dot_seen = 1;
                    } else if (num_str[k] >= '0' && num_str[k] <= '9') {
                        num = num * 10 + (num_str[k] - '0');
                        if (dot_seen) {
                            factor *= 10;
                        }
                    }
                }

                *(double *)arg = num / factor;
                total_conversions++;

                format++;  // Skip 'f' to avoid infinite loop
            }
            // Handle character parsing (%c)
            else if (*format == 'c') {
                ch = getchar();
                *(char *)arg = ch;
                total_conversions++;
            }
            // Handle string parsing (%s)
            else if (*format == 's') {
                char temp_str[1024];
                int j = 0;

                ch = getchar();
                // Skip leading whitespace
                while (ch == ' ' || ch == '\t' || ch == '\n') {
                    ch = getchar();
                }

                // Read the string until whitespace or EOF
                while (ch != EOF && ch != ' ' && ch != '\t' && ch != '\n' && j < sizeof(temp_str) - 1) {
                    temp_str[j++] = ch;
                    ch = getchar();
                }
                temp_str[j] = '\0';

                strcpy((char *)arg, temp_str);
                total_conversions++;
            }
            // Handle invalid format specifiers
            else {
                break;
            }

            format++;  // Move past the format specifier (e.g., 'd', 's', 'f', etc.)
        } else {
            // If no '%' is found, simply skip over the character in the format string
            format++;
        }
    }

    return total_conversions;
}

