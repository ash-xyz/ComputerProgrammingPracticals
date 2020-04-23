#include <stdio.h>

int twoBig(int *a, int size)
{
    int max = 0;
    int secondMax = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > a[max])
        {
            secondMax = max;
            max = i;
        }
    }
    return secondMax;
}

int main()
{
    int arr[] = {1, 2, 5, 3, 6, 9};
    printf("%d", twoBig(arr, 6));
}