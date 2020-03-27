/*Ashraf Ali - 19315281*/

#include <stdio.h>

int main(void)
{
    /*User Input*/
    int numOfSeconds;
    printf("Enter the number of seconds: ");
    scanf("%d", &numOfSeconds);

    /*Check and Outputs the number of days*/
    int numOfDays = numOfSeconds / 86400;
    /*Only prints if the number of days is greater zero*/
    if (numOfDays > 0)
    {
        /*Prints the number of days and adds an 's' to day if there are more than 1 days*/
        printf("%d Day%c ", numOfDays, numOfDays > 1 ? 's' : '\0');
        /*Removes the days from the number of seconds*/
        numOfSeconds %= 86400;
    }

    /*Check and outputs the number of hours*/
    int numOfHours = numOfSeconds / 3600;
    /*Only prints if the number of hours is greater zero*/
    if (numOfHours > 0)
    {
        /*Prints the number of hours and adds an 's' to hour if there are more than 1 hours*/
        printf("%d hour%c ", numOfHours, numOfHours > 1 ? 's' : '\0');
        /*Removes the hours from the number of seconds*/
        numOfSeconds %= 3600;
    }

    /*Check and outputs the number of minutes*/
    int numOfMinutes = numOfSeconds / 60;
    /*Only prints if the number of minutes is greater zero*/
    if (numOfMinutes > 0)
    {
        /*Prints the number of minutes and adds an 's' to minute if there are more than 1 minutes*/
        printf("%d minute%c ", numOfMinutes, numOfMinutes > 1 ? 's' : '\0');
        /*Removes the minutes from the number of seconds*/
        numOfSeconds %= 60;
    }

    /*Check and Outputs the number of seconds*/
    /*Only prints if the number of seconds is greater zero*/
    if (numOfSeconds > 0)
    {
        /*Prints the number of seconds and adds an 's' to second if there are more than 1 seconds*/
        printf("%d second%c", numOfSeconds, numOfSeconds > 1 ? 's' : '\0');
    }
}