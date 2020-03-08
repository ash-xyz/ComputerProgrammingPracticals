/*Ashraf Ali 07/10/2019 Laboratory 5 Submission Question 2*/
#include <stdio.h>
int main(void)
{
    int i = 0, n;
    /*Sets our variables to be able to compute numbers larger than the 50th pell term*/
    unsigned long long pell1, pell2, pellNext;

    /*Set them as the first two fib terms*/
    pell1 = 0; //n-2
    pell2 = 1; //n-1

    /*User Input*/
    printf("Enter how many terms you want: ");
    scanf("%d", &n);

    /*Getting rid of some user bound errors*/
    if (n >= 1)
    {
        printf("The pell sequence:\n");
        /*Due to the fact c is compiled top down we can set variables to the previous term*/
        for (i; i < n; i++)
        {
            pellNext = (2 * pell2) + pell1;
            printf("%llu \n", pell1);
            pell1 = pell2;
            pell2 = pellNext;
        }
    }
    else
    {
        printf("Please enter a positive whole number");
    }

    return 0;
}