#include <stdio.h>
#include <stdlib.h>

#define FT_TO_MT 0.3048
#define MT_TO_FT 3.28084
#define ML_TO_FT 5280.0
#define FT_TO_ML 0.000189394
#define INCH_TO_CM 2.54
#define CM_TO_INCH 0.393701
#define YD_TO_FT 3.0
#define FT_TO_YD 0.333333

//function to convert number based on the unit
void convert_and_print(double value, char unit)
{
    double result;

    printf("%.2f %c: ", value, unit);

    //convert value to all other units
    switch (unit)
    {
    case 'f': // ft
        printf("ft %.2f, ", value);
        result = value * FT_TO_MT;
        printf("mt %.2f, ", result);
        result = value * FT_TO_ML;
        printf("ml %.2f, ", result);
        result = value * 12.0;
        printf("in %.2f, ", result);
        result = value * 30.48;
        printf("cm %.2f, ", result);
        result = value * FT_TO_YD;
        printf("yd %.2f\n", result);
        break;
    case 'm': // mt
        result = value * MT_TO_FT;
        printf("ft %.2f, ", result);
        printf("mt %.2f, ", value);
        result = value * 0.000621371;
        printf("ml %.2f, ", result);
        result = value * 39.3701;
        printf("in %.2f, ", result);
        result = value * 100.0;
        printf("cm %.2f, ", result);
        result = value * 1.09361;
        printf("yd %.2f\n", result);
        break;
    case 'l': // ml
        result = value * ML_TO_FT;
        printf("ft %.2f, ", result);
        result = value * 1.60934;
        printf("mt %.2f, ", result);
        printf("ml %.2f, ", value);
        result = value * 63360.0;
        printf("in %.2f, ", result);
        result = value * 1609.34;
        printf("cm %.2f, ", result);
        result = value * 1760.0;
        printf("yd %.2f\n", result);
        break;
    case 'i': // in
        result = value / 12.0;
        printf("ft %.2f, ", result);
        result = value * 0.0254;
        printf("mt %.2f, ", result);
        result = value * 1.5783e-5;
        printf("ml %.2f, ", result);
        printf("in %.2f, ", value);
        result = value * 2.54;
        printf("cm %.2f, ", result);
        result = value * 0.0277778;
        printf("yd %.2f\n", result);
        break;
    case 'c': // cm
        result = value / 2.54;
        printf("ft %.2f, ", result);
        result = value / 100.0;
        printf("mt %.2f, ", result);
        result = value * 6.2137e-6;
        printf("ml %.2f, ", result);
        result = value / 2.54;
        printf("in %.2f, ", result);
        result = value * 10.0;
        printf("cm %.2f, ", result);
        result = value / 91.44;
        printf("yd %.2f\n", result);
        break;
    case 'y': // yd
        result = value * YD_TO_FT;
        printf("ft %.2f, ", result);
        result = value / 1.09361;
        printf("mt %.2f, ", result);
        result = value / 1760.0;
        printf("ml %.2f, ", result);
        result = value * 36.0;
        printf("in %.2f, ", result);
        result = value * 91.44;
        printf("cm %.2f, ", result);
        printf("yd %.2f\n", value);
        break;
    }
}

int main()
{
    char unit;
    double value;

    // Reading input and processing it
    printf("Enter length and unit : ");
    while (scanf("%lf %c", &value, &unit) == 2) {
        if (unit == 'f' || unit == 'm' || unit == 'l' || unit == 'i' || unit == 'c' || unit == 'y') {
            convert_and_print(value, unit);
        }
        else {
            printf("Invalid unit.\n");
        }
    }

    return 0;
}
