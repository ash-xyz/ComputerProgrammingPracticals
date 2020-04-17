/*Ashraf Ali 19315281*/
#include <stdio.h>

void printer(int sizeofNums, char *y[]); /*Prints the content of our strings along with the first character in each string*/

int main()
{
    /*Making our inputs*/
    char a[] = "one";
    char b[] = "two";
    char c[] = "three";
    char d[] = "four";
    char e[] = "five";
    char *nums[] = {a, b, c, d, e};

    /*Calculates the length of our input array and then passes it and the length to be printed*/
    printer(sizeof(nums) / sizeof(nums[0]), nums);
}

/*Prints the content of our strings along with the first character in each string*/
void printer(int sizeofNums, char *y[])
{
    /*Loops through each string in the input array*/
    for (int i = 0; i < sizeofNums; i++)
    {
        /*Prints the string alongside the first character*/
        printf("Word %d is %s. The first letter of the word is %c\n", i + 1, y[i], y[i][0]);
    }
}