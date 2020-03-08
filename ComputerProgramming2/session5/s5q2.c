/*Ashraf Ali - 19315281 - 25/02/2020*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reverseArray(int arraySize, int a[]);                                              //A function to reverse an array of integers
void randomiseArray(int arraySize, int a[]);                                            // A function to randomly shuffle an array of integers
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[])); //Executes a chosen function and then prints the array

int main(void)
{

    /*Introduction and example*/
    printf("Input a list of numbers and you can either choose to reverse them or shuffle them.\nHere's an example: \n");
    /*Sample array which is printed*/
    int exampleArray[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    printf("The array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", exampleArray[i]);
    }
    /*Reverses the array*/
    printf("\n\nThe reversed array: \n");
    printArray(10, exampleArray, reverseArray);
    /*Randomises and prints the array*/
    printf("\n\nThe randomised array: \n");
    printArray(10, exampleArray, randomiseArray);

    /*Asks user for the length of the array*/
    int arraySize;
    printf("\n\nEnter how long you would like your array to be: ");
    scanf("%d", &arraySize);

    /*Asks users to enter the contents of their array*/
    int userArray[arraySize];
    printf("\nEnter the numbers in your array: \n");
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &userArray[i]);
    }
    /*Prints the array*/
    printf("The array: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", userArray[i]);
    }

    /*Asks the user whether to reverse or shuffle*/
    int choice;
    printf("\n\nChoose 1 to reverse and choose 2 to shuffle: ");
    scanf("%d", &choice);

    /*Option 1 prints a reversed array*/
    if (choice == 1)
    {
        printArray(arraySize, userArray, reverseArray);
    }
    /*Option 2 prints a randomly shuffled array*/
    else if (choice == 2)
    {
        printArray(arraySize, userArray, randomiseArray);
    }
}

/*Reverses an array of integers*/
void reverseArray(int arraySize, int a[])
{
    /*Starts at both ends of an array and moves inwards whilist swapping the values at those two ends*/
    for (int i = 0, j = arraySize - 1; i < j; i++, j--)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
void randomiseArray(int arraySize, int a[])
{
    /*Ensures better randomness*/
    srand(time(NULL));

    /*It randomly shuffles between 50 to 100 times*/
    int shuffleLength = rand() % 50 + 50;

    /*Loops until it has snuffled the specified numebr of times*/
    while (shuffleLength > 0)
    {
        /*Retrieves 2 random indexes, 0,(arraySize - 1)*/
        int i = rand() % arraySize;
        int j = rand() % arraySize;

        /*Swaps the two random indexes with eachother*/
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        shuffleLength--;
    }
}
/*Executes a specified function and then prints the contents of the integer array following its execution*/
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[]))
{
    /*Executes a specified function*/
    (*arrayFunction)(arraySize, a);

    /*Prints the altered integer array*/
    printf("Your new array: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", a[i]);
    }
}