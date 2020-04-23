#include <stdio.h>
int arraySum(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int myArray2[5] = {9, 9, 9, 3, 7};
    printf("%d\n", arraySum(myArray2, 5));
}