/*Ashraf Ali 19315281 11/11/2019*/
#include <stdio.h>
#include <string.h>
#define MAX 50

int main(void)
{
    /*INPUT*/
    char msg[MAX];
    printf("Please enter a string: ");
    fgets(msg, MAX, stdin);

    for (int i = 0; msg[i] != '\0'; i++)
    {
        /*39 is the ascii nmber for apostrophe*/
        if (msg[i] == '!' || msg[i] == 39 || msg[i] == '?' || msg[i] == ';' || msg[i] == ':' || msg[i] == ',' || msg[i] == '.')
        {
            /*Replaces any punctuation marks with spaces*/
            msg[i] = 32;
        }
    }

    /*OUTPUT: with no extra spaces between words*/
    printf("Your new string is: ");
    for (int i = 0; msg[i] != '\0'; i++)
    {
        if (msg[i] != 32 || msg[i - 1] != 32)
        {
            printf("%c", msg[i]);
        }
    }
    return 0;
}