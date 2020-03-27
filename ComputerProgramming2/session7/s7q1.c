/*Ashraf Ali - 19315281*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printList(char **list, int listLength);      //Prints all the words in the list
void shuffleList(char **list, int listLength);    //Shuffles a List of Strings - Using Fisher Yates Shuffle Algorithm
void pickRandomWord(char **list, int listLength); //Picks and prints a random word from the list

int main()
{
    /*Seeds the random function according to the time*/
    srand(time(NULL));

    /*Array of pointers storing an array of characters*/
    char *listOfWords[13] = {"COMP10120", "is", "my", "favourite", "module", "and", "I", "learn", "lots", "of", "interesting", "things"};

    /*Loop to ask users which function they want to use*/
    int choice = -1;
    while (choice != 0)
    {
        /*Displays information to user*/
        printf("Enter 1 to print the list of words\n");
        printf("Enter 2 shuffle the list of words\n");
        printf("Enter 3 to pick and print a random word\n");
        printf("Enter 0 to quit\n");
        printf("Enter: ");

        /*Retrieves choice from user*/
        scanf("%d", &choice);

        /*Executes a function according to the user choice*/
        switch (choice)
        {
        case 1:
            /*Prints the list of words*/
            printList(listOfWords, 12);
            break;
        case 2:
            /*Shuffles the list of words*/
            shuffleList(listOfWords, 12);
            break;
        case 3:
            /*Picks and prints a random word*/
            pickRandomWord(listOfWords, 12);
            break;
        case 0:
            /*Exists program*/
            return 0;
            break;
        default:
            printf("Enter a valid choice");
        }
        printf("\n");
    }
    return 0;
}

/*Prints all the words in the list*/
void printList(char *list[], int listLength)
{
    printf("\nPrinted List of Words:\n");
    /*Goes throught the array in order and prints each word, enclosed by quotation marks*/
    for (int i = 0; i < listLength; i++)
    {
        printf("\"%s\" ", list[i]);
    }
    printf("\n");
}

/*Shuffles a List of Strings - Using Fisher Yates Shuffle Algorithm*/
void shuffleList(char *list[], int listLength)
{
    for (int i = listLength - 1; i > 0; i--)
    {
        /*Randomly chooses an index between 1 and i to shuffle with i*/
        int j = rand() % (i + 1);

        /*Swaps strings i and j together*/
        char *temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}

/*Picks and prints a random word from the list*/
void pickRandomWord(char *list[], int listLength)
{
    /*Picks a random index between 1 and the length of index*/
    int randomIndex = rand() % listLength;
    /*Prints the word stored in the random index*/
    printf("\nRandom Word: \"%s\"\n", list[randomIndex]);
}