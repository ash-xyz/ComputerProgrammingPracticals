/* Ashraf Ali - 19315281 - 28/01/2020*/
/*Write a program in C which determines if a number is a prime number or not.  */
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main(void)
{
    int n;
    /*INPUT*/
    printf("Please enter a number to check if it's a prime: ");
    scanf("%d", &n);

    /*OUTPUT*/
    isPrime(n) ? printf("It is a prime") : printf("It is not a prime");

    return 0;
}
bool isPrime(int n)
{

    int i;
    /*CHECKS IF n IS NOT DIVISIBLE BY i | 2<=i<=n-1*/
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return i == n;
}