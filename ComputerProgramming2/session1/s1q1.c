/* Ashraf Ali - 19315281 - 28/01/2020*/
/* Write a C program that inputs the height of 3 children in a class (in cm). The programme should then calculate the tallest, shortest and the average height.*/
#include <stdio.h>

int meanHeight(int person1, int person2, int person3);
int tallest(int person1, int person2, int person3);
int shortest(int person1, int person2, int person3);

int main(void)
{
    int child1, child2, child3;

    /*INPUT*/
    printf("Enter the height of child 1 in cm:");
    scanf("%d", &child1);

    printf("Enter the height of child 2 in cm:");
    scanf("%d", &child2);

    printf("Enter the height of child 3 in cm:");
    scanf("%d", &child3);

    /*Output*/
    printf("The average height is: %d\n", meanHeight(child1, child2, child3));
    printf("The tallest height is: %d\n", tallest(child1, child2, child3));
    printf("The shortest height is: %d\n", shortest(child1, child2, child3));

    return 0;
}

/*Finds the average of three integers*/
int meanHeight(int person1, int person2, int person3)
{
    int mean = (person1 + person2 + person3) / 3;
    return mean;
}

/*Find the largest of three integers*/
int tallest(int person1, int person2, int person3)
{
    if (person1 >= person2 && person1 >= person3)
    {
        return person1;
    }
    if (person2 >= person1 && person2 >= person3)
    {
        return person2;
    }
    return person3;
}

/*Finds the smallest of three integers*/
int shortest(int person1, int person2, int person3)
{
    if (person1 <= person2 && person1 <= person3)
    {
        return person1;
    }
    if (person2 <= person1 && person2 <= person3)
    {
        return person2;
    }
    return person3;
}