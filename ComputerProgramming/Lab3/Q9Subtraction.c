/*Ashraf Ali 21/09/2019 Laboratory 3 Submission Question 9*/
#include <stdio.h>

/*Where our code runs*/
int main()
{
    /*Initializes our variables as integers for whole numbers*/
    int firstNumber, secondNumber, answer;

    /*Asks user for variables*/
    printf("Enter first number ");
    scanf("%d", &firstNumber);

    printf("Enter second number ");
    scanf("%d", &secondNumber);
    //Where out calculations take place
    answer = firstNumber - secondNumber;

    // Printing our result
    printf(" %d - %d = %d \n", firstNumber, secondNumber, answer);
    return 0;
}