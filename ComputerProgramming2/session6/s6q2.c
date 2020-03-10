/*Ashraf Ali - 19315281 - Practical 6 Question 2*/
#include <stdarg.h>
#include <stdio.h>
#include <stdarg.h>

int adder(int i, ...);
int multiplier(int i, ...);
void myPrinter(char *types, ...);

int main()
{
    /*Calls the myPrinter function to print varying types of input*/
    printf("Example Prints statement:\n");
    myPrinter("dffsc", 1, 1.0, 3.14, "Hello There", 'f');

    /*Calls the adder function to print the addition of 4 numbers*/
    printf("\nExample adder:\n");
    int sum = adder(4, 1, 2, 3, 4);
    printf("1 + 2 + 3 + 4 = %d", sum);

    /*Calls the multiplier function to print the multiplication of 4 numbers*/
    printf("\n\nExample multiplier:\n");
    int total = multiplier(4, 1, 2, 3, 4);
    printf("1 x 2 x 3 x 4 = %d", total);
}

/*Takes a string as an argument which specifies the types of each argument in the variable length arguments*/
void myPrinter(char *types, ...)
{
    /*Stores information required by va_start and va_end*/
    va_list inputs;

    /*initialises inputs*/
    va_start(inputs, types);

    /*Transverses string of types and prints each value relative to their type*/
    while (*types != '\0')
    {
        switch (*types)
        {
            /*Prints integer types*/
        case 'd':
            printf("%d\n", va_arg(inputs, int));
            break;
            /*Prints float types*/
        case 'f':
            printf("%f\n", va_arg(inputs, double));
            break;
            /*Prints character types*/
        case 'c':
            printf("%c\n", (char)va_arg(inputs, int));
            break;
            /*Prints string types*/
        case 's':
            printf("%s\n", va_arg(inputs, char *));
            break;
        default:
            break;
        }
        /*Increments the pointer value*/
        types++;
    }
    /*Cleans up variable length argument list*/
    va_end(inputs);
}

/*Takes in a specified number of integers and returns their sum*/
int adder(int i, ...)
{
    /*Variable to store the arithmetic sum of all the arguments*/
    int sum = 0;

    /*Stores information required by va_start and va_end*/
    va_list inputs;

    /*Initialises inputs*/
    va_start(inputs, i);

    /*Tranverses list of arguments and sums them together*/
    for (int j = 0; j < i; j++)
    {
        sum += va_arg(inputs, int);
    }
    /*Cleans up variable length argument list*/
    va_end(inputs);

    return sum;
}

/*Takes in a specified number of integers(i) and returns their product*/
int multiplier(int i, ...)
{
    /*Stores the product of all the arguments*/
    int total = 1;

    /*Stores information require by va_start and va_end*/
    va_list inputs;

    /*Initialises inputs*/
    va_start(inputs, i);

    /*Tranverses list of arguments and multiplies them together*/
    for (int j = 0; j < i; j++)
    {
        total *= va_arg(inputs, int);
    }
    /*Cleans up variable length argument list*/
    va_end(inputs);
    return total;
}