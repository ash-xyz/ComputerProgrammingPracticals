/* Ashraf Ali - 19315281 - 28/01/2020*/
/* Write a program in C to find area and circumference of circle.*/

#include <stdio.h>
#define PI 3.14159265358979323846 // PI to the
int main(void)
{
    double radius;

    /*INPUT*/
    printf("Enter the radius of your circle: ");
    scanf("%lf", &radius);

    /*CALCULATIONS*/
    double areaOfCircle = PI * radius * radius;
    double circumferenceOfCircle = 2 * PI * radius;

    /*OUTPUT*/
    printf("Area of Circle = %.2lf\n", areaOfCircle);
    printf("Circumference of circle = %.2lf", circumferenceOfCircle);
    return 0;
}