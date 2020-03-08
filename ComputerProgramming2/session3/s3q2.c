/*Ashraf Ali 19315281 - 12/02/2020*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int **generateArray(int rowSize, int columnSize, bool *exists);                   //Generates and returns a 2d array of a defined size, whilist making sure it doesn't repeat it's self
void printArray(int **array, int rowSize, int columnSize);                        // Prints a 2d array
int **sumCells(int **arrayA, int **arrayB, int rowSize, int columnSize);          //A function that returns a 2D array that contains the sum of corresponsing cells in 2 2D arrays
int **productCells(int **arrayA, int **arrayB, int rowSize, int columnSize);      //A function that returns a 2d array containing the product of the corresponding cells in 2 2D arrays
int *sumOfRows(int **arrayA, int **arrayB, int rowSize, int columnSize);          //A function that returns an array containing the sum of the rows in two arrays
int *sumOfColumns(int **arrayA, int **arrayB, int rowSize, int columnSize);       //A function that returns array containing the sum of the columns in two arrays
int uniqueNumbers(bool *existsA, bool *existsB);                                  // Finds the total number of numbers occuring in two arrays, |A U B| = |A| + |B| - |A n B|
void sameNumberSameCell(int **arrayA, int **arrayB, int rowSize, int columnSize); //Prints out 'WOW' if a number appears in two arrays at the same cell

int main(void)
{
    /*Used to stop numbers from repeating, also used to determine the number of numbers occuring in both arrays
    Hence sacrificing space for time. */
    bool *existsArrayA = malloc(1400 * sizeof(bool)); // Stores whether or not a number has been used in array A.
    bool *existsArrayB = malloc(1400 * sizeof(bool)); // Stores whether or not a number has been used in array B.

    srand(time(NULL)); // Seeds the random function

    int rowSize, columnSize;

    /*INPUT Size of Array*/
    printf("Please enter how many rows you want(so long as they are less than 20): ");
    scanf("%d", &rowSize);
    printf("Please enter how many columns you want(so long as they are less than 20): ");
    scanf("%d", &columnSize);

    /*Checks if either the row or column size entered is greater than 20*/
    if (rowSize > 20 || columnSize > 20)
    {
        printf("You have entered too many rows");
        return 0;
    }

    /*Generates the first random 2D array*/
    int **arrayA = generateArray(rowSize, columnSize, existsArrayA);
    printf("Array A: \n");
    printArray(arrayA, rowSize, columnSize); // Prints Array A

    /*Generates the second random 2D array*/
    int **arrayB = generateArray(rowSize, columnSize, existsArrayB);
    printf("Array B: \n");
    printArray(arrayB, rowSize, columnSize); // Prints Array B

    /*Sums of the 2D arrays*/
    int **sumOfArray = sumCells(arrayA, arrayB, rowSize, columnSize);
    printf("The sum of corresponding cells in Array A and Array B: \n");
    printArray(arrayA, rowSize, columnSize); // Prints the sumOfthe Array
    free(sumOfArray);                        // Frees the array in Memory

    /*Product of the 2D Arrays*/
    int **productOfArray = productCells(arrayA, arrayB, rowSize, columnSize);
    printf("The product of corresponding cells in Array A and Array B: \n");
    printArray(productOfArray, rowSize, columnSize); // Prints the product of the two arrays
    free(productOfArray);                            // Frees the array in Memory

    /*Sum of corresponding rows in arrayA and arrayB*/
    int *sumOfRow = sumOfRows(arrayA, arrayB, rowSize, columnSize);
    printf("Sum of corresponding rows in arrayA and arrayB\n");
    for (int i = 0; i < columnSize; i++)
        printf("%d ", sumOfRow[i]); //Prints out the an array with the sum of the rows
    free(sumOfRow);                 // Frees the array in Memory

    /*Sum of corresponding columns in arrayA and arrayB*/
    int *sumOfColumn = sumOfColumns(arrayA, arrayB, rowSize, columnSize);
    printf("\n\nSum of corresponding rows in arrayA and arrayB\n");
    for (int i = 0; i < rowSize; i++)
        printf("%d ", sumOfColumn[i]); //Prints out the an array with the sum of the rows
    free(sumOfColumn);                 //Frees the array in Memory

    /*Finds the total number of unique numbers that occur in both A and B, i.e. the count of the union of A and B*/
    int countOfUniqueNumbers = uniqueNumbers(existsArrayA, existsArrayB);
    printf("\n\nThe total number of numbers that occur in both A and B is: %d", countOfUniqueNumbers);
    free(existsArrayA); //Frees the boolean array in Memory
    free(existsArrayB);

    /*Prints Wow if the same number appears in the same cell in the two arrays*/
    sameNumberSameCell(arrayA, arrayB, rowSize, columnSize);

    /*Free our two generate arrays*/
    free(arrayA);
    free(arrayB);

    return 0;
}

int **generateArray(int rowSize, int columnSize, bool *exists)
{
    /*Generates the rows of our 2D array*/
    int **array = (int **)malloc(sizeof(int *) * rowSize);

    for (int i = 0; i < rowSize; i++)
    {
        /*Generates the Columns for our 2D arrays*/
        array[i] = (int *)malloc(sizeof(int) * columnSize);
        for (int j = 0; j < columnSize; j++)
        {
            //Chooses a random number between 100-1500
            array[i][j] = rand() % 1400 + 100;

            /*Checks whether or not the random number was previously generated, Checking whether it exists runs in O(1) time*/
            while (exists[array[i][j] - 100])
            {
                array[i][j] = rand() % 1400 + 100;
            }
            /*Add the generated number to our boolean array*/
            exists[array[i][j] - 100] = true;
        }
    }
    return array;
}

//Function that takes a 2d array as input, and prints it out
void printArray(int **array, int rowSize, int columnSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < columnSize; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//A function that returns a 2D array that contains the sum of corresponsing cells in 2 2D arrays
int **sumCells(int **arrayA, int **arrayB, int rowSize, int columnSize)
{
    /*Generates the rows of 2D Array*/
    int **arraySums = (int **)malloc(sizeof(int *) * rowSize);

    for (int i = 0; i < rowSize; i++)
    {
        /*Generates the columns for the 2D array*/
        arraySums[i] = (int *)malloc(sizeof(int) * columnSize);
        for (int j = 0; j < columnSize; j++)
        {
            /*stores the sums of the corresponding cells of arrayA and arrayB in arraySums*/
            arraySums[i][j] = arrayA[i][j] + arrayB[i][j];
        }
    }
    return arraySums;
}

//A function that returns a 2d array containing the product of the corresponding cells in 2 2D arrays
int **productCells(int **arrayA, int **arrayB, int rowSize, int columnSize)
{
    /*Generates the rows of 2D Array*/
    int **productArray = (int **)malloc(sizeof(int *) * rowSize);

    for (int i = 0; i < rowSize; i++)
    {
        /*Generates the columns for the 2D array*/
        productArray[i] = (int *)malloc(sizeof(int) * columnSize);
        for (int j = 0; j < columnSize; j++)
        {
            /*Stores the product of the corresponding cells in each array*/
            productArray[i][j] = arrayA[i][j] * arrayB[i][j];
        }
    }
    return productArray;
}
//A function that returns an array containing the sum of the rows in two arrays
int *sumOfRows(int **arrayA, int **arrayB, int rowSize, int columnSize)
{
    /*Generates an array the size of columnSize*/
    int *sumOfRow = malloc(columnSize * sizeof(int));

    for (int i = 0; i < columnSize; i++)
    {
        int sum = 0;
        for (int j = 0; j < rowSize; j++)
        {
            sum += arrayA[j][i] + arrayB[j][i];
        }
        sumOfRow[i] = sum;
    }
    return sumOfRow;
}
//A function that returns array containing the sum of the columns in two arrays
int *sumOfColumns(int **arrayA, int **arrayB, int rowSize, int columnSize)
{
    /*Generates an array the size of rowsize*/
    int *sumOfColumn = malloc(rowSize * sizeof(int));

    for (int i = 0; i < rowSize; i++)
    {
        int sum = 0;
        for (int j = 0; j < columnSize; j++)
        {
            sum += arrayA[j][i] + arrayB[j][i];
        }
        sumOfColumn[i] = sum;
    }
    return sumOfColumn;
}

// Finds the total number of numbers occuring in two arrays, |A U B| = |A| + |B| - |A n B|
int uniqueNumbers(bool *existsA, bool *existsB)
{
    int count = 0;
    for (int i = 0; i < 1400; i++)
    {
        //Only counts numbers occuring in A and B once
        if (existsA[i] && existsB[i])
        {
            count++;
        }
        else if (existsA[i])
        {
            count++;
        }
        else if (existsB[i])
        {
            count++;
        }
    }
    return count;
}
//Prints out 'WOW' if a number appears in two arrays at the same cell
void sameNumberSameCell(int **arrayA, int **arrayB, int rowSize, int columnSize)
{
    /*Loops through both arrays comparing their corresponding cells. If the value of their corresponding cells is equal, 'WOW' is printed*/
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < columnSize; j++)
        {
            if (arrayA[i][j] == arrayB[i][j])
            {
                printf("\n\nWOW!!! The number %d, appears in both arrays, at the same cell, in row: %d and column: %d!", arrayB[i][j], i, j);
            }
        }
    }
}