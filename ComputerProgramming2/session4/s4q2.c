/*Ashraf Ali - 18/02/2020 - 19315281*/

#include <stdio.h>
#include <stdlib.h>

void copyArrayIndexWay(char *const newArray1, const char *const originalArray1);
void copyPointerWay(char *newArray2, const char *originalArray2);

int main(void)
{
    /*Source of the string to be copied*/
    char originalArray1[] = "COMP10120";
    char originalArray2[] = "COMP10110";

    /*Destination of the copied string; Initialized to NULL*/
    char newArray1[10] = {'\0'};
    char newArray2[10] = {'\0'};

    /*Copies strings using array indexing ~ OUTPUT*/
    copyArrayIndexWay(newArray1, originalArray1);
    printf("%s\n", newArray1);

    /*Copies strings using pointers ~ OUTPUT*/
    copyPointerWay(newArray2, originalArray2);
    printf("%s\n", newArray2);

    return 0;
}

void copyArrayIndexWay(char *const newArray1, const char *const originalArray1)
{
    /*Transverses the string array until a null pointer is hit*/
    for (int i = 0; originalArray1[i] != '\0'; i++)
    {
        /*Takes the value of each character at index i and stores it in newArray*/
        newArray1[i] = originalArray1[i];
    }
}

void copyPointerWay(char *newArray2, const char *originalArray2)
{
    /*Transverses the string until the pointer is null*/
    while (*originalArray2)
    {
        /*New array takes the value of the current character in the old array*/
        *newArray2 = *originalArray2;
        /*Positions in the strings are incremented*/
        newArray2++;
        originalArray2++;
    }
}