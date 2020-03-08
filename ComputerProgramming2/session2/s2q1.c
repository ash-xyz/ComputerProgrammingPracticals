/*Ashraf Ali - 19315281 - 04/02/2020*/
#include <stdio.h>

int dayOfTheWeek(int dayOfMonth, int month, int year);
int main(void)
{
    int date, month, year;
    //DATE INPUT
    printf("Enter the date: ");
    scanf("%d", &date);
    //MONTH INPUT
    printf("Enter the month: ");
    scanf("%d", &month);
    //YEAR INPUT
    printf("Enter the year: ");
    scanf("%d", &year);

    //Retrieves the day of the week(Monday-Sunday) as an integer value(1-7)
    int dayOfWeek = dayOfTheWeek(date, month, year);

    /*OUTPUT*/
    printf("%d/%d/%d: ", date, month, year);
    //Prints out the day of the week depending on the value of 'dayOfWeek'
    switch (dayOfWeek)
    {
    case 0:
        printf("Monday \n");
        break;
    case 1:
        printf("Tuesday \n");
        break;
    case 2:
        printf("Wednesday \n");
        break;
    case 3:
        printf("Thursday \n");
        break;
    case 4:
        printf("Friday \n");
        break;
    case 5:
        printf("Saturday \n");
        break;
    case 6:
        printf("Sunday \n");
        break;
    }
    return 0;
}
/*Zeller’s Congruence Algorithm.*/
int dayOfTheWeek(int dayOfMonth, int month, int year)
{

    /*The Algorithm takes January and Feburary to be the 13th and 14th month, respectively, of the previous year, the following if statments adjust for that*/
    if (month == 1)
    {
        month = 13;
        year--;
    }
    if (month == 2)
    {
        month = 14;
        year--;
    }
    int centuryBasedYear = year % 100; // Year of the century, e.g. 1999 is 99 and 2000 is 00
    int zeroBasedCentury = year / 100; // Year of the Century, e.g. 1999 is 19 and 2000 is 20

    /*Calculations*/
    int dayOfWeek = dayOfMonth + 13 * (month + 1) / 5 + centuryBasedYear + centuryBasedYear / 4 + zeroBasedCentury / 4 + 5 * zeroBasedCentury;
    /*Returns day of the week Monday-Friday as an integer 1-7*/
    return ((dayOfWeek + 5) % 7);
}