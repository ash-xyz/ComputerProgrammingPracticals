/*Ashraf Ali 07/10/2019 Laboratory 5 Submission Question 3*/
#include <stdio.h>
int main(void)
{
    float arr[4], w, x, y, z;

    /*User Input*/
    for (int i = 0; i < 4; i++)
    {
        printf("Enter Value %d: ", (i+1));
        scanf("%f", &arr[i]);
    }

    //Selection Sort Algorithm 
    for (int i = 0; i < 3; i++)
    {
        int min = i;
        for (int j = i + 1; j < 4; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    //Setting our W, X, Y & Z
    w = arr[0];
    x = arr[1];
    y = arr[2];
    z = arr[3];

    //Printing our variables
    printf("W, X, Y & Z, respectively, are: %.2f, %.2f, %.2f & %.2f", w, x, y, z);

    return 0;
}