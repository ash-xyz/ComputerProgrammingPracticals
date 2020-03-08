/*Ashraf Ali 19315 281 29/10/2019 Labaratory 8 Q1 in O(N^2) time*/
#include <stdio.h>

int main()
{
    /*USER INPUT; Size of Array*/
    int N;
    printf("Enter how long you want your Array to be: ");
    scanf("%d", &N);

    /*USER INPUT; Contents of Array*/
    printf("Enter the contents of your Array: \n");
    int a[N];
    for (int i = 0; i < N; i++)
    {
        printf("Value %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    int value = 0;
    int count = 0;
    /*Brute Force Method*/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i] == a[j])
            {
                value = a[j];
                count++;
                if (count > N - 2)
                {
                    printf("Your answer is: %d", value);
                    return 0;
                }
            }
        }
    }
    printf("No value with a frequency greater than N/2 exists!");
}