/*Ashraf Ali - 19315281 - 04/02/2020*/
#include <stdio.h>

int printMultiplicationTable(int number, int sizeOfTimesTable);
int main(void)
{
    int num, size;

    /*INPUT: Number to be Multiplied*/
    printf("Enter a number: ");
    scanf("%d", &num);
    /*Input: Size of Multiplication Table*/
    printf("Enter the size of your multiplication Table: ");
    scanf("%d", &size);

    /*Function to print the multiplication tables*/
    printf("Here is your multiplication table:\n");
    printMultiplicationTable(num, size);
    return 0;
}
int printMultiplicationTable(int number, int sizeOfTimesTable)
{
    if (sizeOfTimesTable <= 0)
        return 0;

    /*Recursive Element ~ Bottom Up*/
    printMultiplicationTable(number, sizeOfTimesTable - 1);

    int multiplication = number * sizeOfTimesTable;
    /*OUTPUT*/
    printf("%d * %d = %d\n", number, sizeOfTimesTable, multiplication);
}