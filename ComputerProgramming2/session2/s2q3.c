/*Ashraf Ali - 19315281 - 04/02/2020*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void powerballGenerator();
int main(void)
{
    //Function to generate and print
    powerballGenerator();
    return 0;
}

/*Generates a random number between 1 and n*/
void powerballGenerator()
{
    srand(time(NULL)); // Seeds random to achieve less predictable randomness

    printf("The first five numbers are: ");
    for (int i = 0; i < 6; i++)
    {
        if (i < 5)
        {
            printf("%d ", rand() % 39 + 1);
        }
        else
        {
            printf("and your Thunderball is: ");
            printf("%d!", rand() % 14 + 1);
        }
    }
}