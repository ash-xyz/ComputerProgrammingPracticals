/* Ashraf Ali - 19315281 - 28/01/2020*/
/* Write a C program that allows you to enter your student number from the keyboard and then prints each digit on a new line. It should also sum the numbers.*/
#include <stdio.h>

int main(void)
{
    int sum = 0;
    char studentNumber[9];

    /*INPUT*/
    printf("Enter an 8 digit student number: ");
    scanf("%s", &studentNumber);

    for (int i = 0; i < 8; i++)
    {
        printf("%c \n", studentNumber[i]);//Prints out each number in the Student Number
        sum += (studentNumber[i] - '0');//Sums the numbers of the student numbers
    }

    /*OUTPUT - SUM OF STUDENT NUMBERS*/
    printf("The sum is: %d", sum);

    return 0;
}