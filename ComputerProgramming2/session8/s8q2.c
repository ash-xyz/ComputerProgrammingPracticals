/*Ashraf Ali - 19315281*/

#include <stdio.h>
#include <stdlib.h>

int *declareInteger(int sizeOfArray); //Declares integer array and asks the user to fill it
float *declareFloat(int sizeOfArray); //Declares float array and asks the user to fill it

int main()
{
    int type, sizeOfArray;

    /*Inputs the type, 1 for integer, any other integer for float*/
    printf("Enter the the type of element you want to use\nEnter 1 for integer, and any other integer for float: ");
    scanf("%d", &type);

    /*Inputs the size of the array*/
    printf("Enter the size of the array: ");
    scanf("%d", &sizeOfArray);

    /*Declares 2 types, integer and float and allocates memory only for the chosen type*/
    int *integerArray;
    float *floatArray;
    if (type == 1)
    {
        /*Declares an integer array and asks the user to fill it*/
        integerArray = declareInteger(sizeOfArray);
    }
    else
    {
        /*Declares a float array and asks the user to fill it*/
        floatArray = declareFloat(sizeOfArray);
    }

    /*Calculates the average of the elements in the array*/
    float average = 0;
    /*Computes the sum of the elements in an integer array*/
    if (type == 1)
    {
        for (int i = 0; i < sizeOfArray; i++)
        {
            average += integerArray[i];
        }
    }
    /*Computes the sum of the elements in a float array*/
    else
    {
        for (int i = 0; i < sizeOfArray; i++)
        {
            average += floatArray[i];
        }
    }
    average /= sizeOfArray; //Divides the sum by size of the array to achieve the average
    printf("\nAverage: %f\n", average);

    /*Asks users whether or not to allocate more memory for their arrays - if yes it allocates memory and then calculates a new average*/
    int reallocQuestion, reallocSpace;
    printf("Would you like to add more elements to your array?\nEnter 1 for yes, and anything else for no: ");
    scanf("%d", &reallocQuestion);
    if (reallocQuestion == 1)
    {
        /*Prompts user to enter the amount of elements they'd like to add to array*/
        printf("How many more elements would you like added: ");
        scanf("%d", &reallocSpace);
        sizeOfArray += reallocSpace;

        /*Allocates more space to our previousy chosen array type*/
        if (type == 1)
        {
            /*Reallocates more space and asks user to input values for our newly generated elements*/
            integerArray = (int *)realloc(integerArray, sizeOfArray * sizeof(int));
            for (int i = sizeOfArray - reallocSpace; i < sizeOfArray; i++)
            {
                printf("Enter the value of index %d: ", i);
                scanf("%d", &integerArray[i]);
            }
        }
        else
        {
            /*Reallocates more space and asks user to input values for our newly generated elements*/
            floatArray = (float *)realloc(floatArray, sizeOfArray * sizeof(float));
            for (int i = sizeOfArray - reallocSpace; i < sizeOfArray; i++)
            {
                printf("Enter the value of index %d: ", i);
                scanf("%f", &floatArray[i]);
            }
        }

        /*Calculates the average of the elements in chosen array type*/
        average = 0;
        /*Computes sum of the elements in the integer array*/
        if (type == 1)
        {
            for (int i = 0; i < sizeOfArray; i++)
            {
                average += integerArray[i];
            }
        }
        /*Computes sum of the elements in the float array*/
        else
        {
            for (int i = 0; i < sizeOfArray; i++)
            {
                average += floatArray[i];
            }
        }
        average /= sizeOfArray; //Divides them by the size of the array to compute the average
        printf("\nNew Average: %f", average);
    }

    /*Frees allocated memory for the chosen array type*/
    type == 1 ? free(integerArray) : free(floatArray);

    return 0;
}

/*Allocates memory for an integer array and asks user to input the elments of the array, then returns that array*/
int *declareInteger(int sizeOfArray)
{
    /*Allocates memory*/
    int *integerArray = (int *)calloc(sizeOfArray, sizeof(int));
    /*Asks user to input the elements of the array*/
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter the value of index %d in your integer array: ", i);
        scanf("%d", &integerArray[i]);
    }
    return integerArray;
}

/*Allocates memory for an integer array and asks user to input the elments of the array, then returns that array*/
float *declareFloat(int sizeOfArray)
{
    /*Allocates memory*/
    float *floatArray = (float *)calloc(sizeOfArray, sizeof(float));
    /*Asks user to input the elements of the array*/
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("Enter the value of index %d in your float array: ", i);
        scanf("%f", &floatArray[i]);
    }
    return floatArray;
}