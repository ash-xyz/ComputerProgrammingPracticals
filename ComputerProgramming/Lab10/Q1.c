/*Ashraf Ali 19315281 11/11/2019*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int main(void)
{
    char msg[MAX]; // String must be less than 100 charachters

    /*USER INPUT*/
    printf("Please enter a sentence less than 50 charachters of length: ");
    fgets(msg, MAX, stdin);

    int count = 0;
    bool isChar = false; //Boolean to determine whether something is the last Charachter of a word

    for (int i = -1; msg[i] != '\0'; ++i)
    {
        isChar = false;
        /*Checks for the last letter of a word*/
        if ((msg[i] != 32 && msg[i + 1] == 32) || (msg[i] != 32 && msg[i + 1] == '\0'))
        {
            isChar = true;
        }
        /*Increments Count*/
        if (isChar == true)
        {
            count++;
        }
    }
    /*OUTPUT*/
    printf("There are %d words in this sentence", count);
    return 0;
}