/* Ashraf Ali - 19315281 - 28/01/2020*/
/*Write a C Program to determine if a year entered by a user is a leap year*/
#include <stdio.h>

int main(void)
{
    int year;

    /*INPUT*/
    printf("Enter any year: ");
    scanf("%d", &year);
    /*A Leap year is any year that is divisible by 4. This doesn't apply to any years divisible by 100, except for years divisible by 400*/
    (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? printf("%d is a leap year", year) : printf("%d is not a leap year", year);
    return 0;
}