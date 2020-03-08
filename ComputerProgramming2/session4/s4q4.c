/*Ashraf Ali - 19315281 - 18/02/2020*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char *userInput = malloc(100 * sizeof(char *)); //Creates an array of pointers of length 100
    int vowelCounter = 0;                           //A counter for the number of vowels
    int consonantCounter = 0;                       //A counter for the number of consonants

    /*User Input*/
    printf("Enter any string (max 100 characters with no spaces): ");
    fgets(userInput, 100, stdin);

    /*Transverses through the string and counts the number of vowels*/
    char *pos = userInput; //Pointer that transverses the string array; Helps us keep track of the current position
    while (*pos)
    {
        char cur = tolower(*pos); //Holds the lowercase value of the character of the currrent position in the string array

        /*Checks if the current position is a vowel and increments the vowel counter accordingly*/
        if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u')
        {
            vowelCounter++;
        }

        /*Checks if the current position is a consonant and increments the consonant counter accordingly*/
        else if (cur >= 'a' && cur <= 'z')
        {
            consonantCounter++;
        }
        pos++; //Increments the current position in the string array by one
    }

    /*Frees the malloced memory for userInput*/
    free(userInput);

    /*OUTPUT*/
    printf("Number of Vowels in String: %d\nNumber of Consonants in String: %d", vowelCounter, consonantCounter);
    return 0;
}