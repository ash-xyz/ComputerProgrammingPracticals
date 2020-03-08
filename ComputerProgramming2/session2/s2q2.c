/*Ashraf Ali - 19315281 - 04/02/2020*/
#include <stdio.h>
int convertToBinary(int decimal);

int main(void)
{
    int decimal;
    /*INPUT*/
    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);
    /*OUTPUT*/
    printf("Here is the binary equivalent: ");
    convertToBinary(decimal); //Recursive Function that takes a decimal as input and prints the binary equivalent

    return 0;
}

int convertToBinary(int decimal)
{
    /*Works by repeatedly dividing & modulo the decimal by 2 until the binary equivalent is printed*/
    /*Bottom Up Recursion*/
    if (decimal > 1)
    {
        convertToBinary(decimal / 2);
    }
    decimal %= 2;
    printf("%d", decimal);
}