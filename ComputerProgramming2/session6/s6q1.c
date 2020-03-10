/*Ashraf Ali - 19315281 - Practical 6 Question 1*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*Contains the location of the game catalogue file*/
char const CATALOGUE_LOCATION[] = "game_catalogue.txt";

/*Data type which stores all necessary information about a game*/
typedef struct Game
{
    /*ID number(1-1000) of the game*/
    int id_number;
    /*Stores Game Title*/
    char title[40];
    /*Stores the name of the developer*/
    char developer[40];
    /*Stores what platform the game is*/
    char platform[40];
    /*Stores the year*/
    int year;

    /*Stores whether or not the game has been borrowed*/
    bool borrowed;
    /*Stores the name of the person borrowing the game, it's empty when nobody has borrowed the game*/
    char name_borrower[40];
    /*Stores when the game was borrowed, it's empty when nobody has borrowed the game*/
    char date_borrowed[12];
} Game;

void initialiseCatalogue(); //Initialises a file with empty Game data types if none exist
void recordCatalogue();     //Allows the user to add games to the catalogue
void printCatalogue();      //Prints the entire available catalgoue
void borrowingInterface();  //Interface for borrowing or returning games
void borrowGame();          //Allows user to borrow available games from the catalogue
void returnGame();          //Allows user to return borrowed games

int main(void)
{
    /*Initialises the catalogue with empty games or previously entered games*/
    initialiseCatalogue();

    /*Recurring Interface for printing, recording & borrowing games*/
    int choice = -1;
    while (choice != 0)
    {
        /*Asks user to choose whether they'd like to print, record or borrow/return games from the catalogue*/
        printf("Enter 1 to print the catalogue\n");
        printf("Enter 2 to record a game in the catalogue\n");
        printf("Enter 3 for borrowing details\n");
        printf("Enter 0 to exit\n");
        printf("Enter: ");
        scanf("%d", &choice);

        /*Executes functions based on user choice*/
        switch (choice)
        {
        case 1:
            printCatalogue();
            break;
        case 2:
            recordCatalogue();
            break;
        case 3:
            borrowingInterface();
            break;
        }
    }
    return 0;
}

/*Initialises a file with empty Game data types if none exist*/
void initialiseCatalogue()
{
    FILE *text_file;

    /*If the file does not already exist, create a new file and fill it with game data types*/
    if (!(text_file = fopen(CATALOGUE_LOCATION, "rb")))
    {
        text_file = fopen(CATALOGUE_LOCATION, "wb+");
        Game game = {0, "", "", "", 0, false, "", ""};
        for (int i = 0; i < 1000; i++)
        {
            fwrite(&game, sizeof(Game), 1, text_file);
        }
    }
    fclose(text_file);
}

/*Interface for choosing whether to borrow or return a game*/
void borrowingInterface()
{
    /*Recurring function which as users whether they want to borrow/return a game*/
    int choice = -1;
    while (choice != 0)
    {
        /*Asks for user input*/
        printf("\nEnter 1 to borrow a game\n");
        printf("Enter 2 to return a game\n");
        printf("Enter 0 to exit\n");
        printf("Enter: ");
        scanf("%d", &choice);
        printf("\n");

        /*Executes function based on user choice*/
        if (choice == 1)
        {
            borrowGame();
        }
        else if (choice == 2)
        {
            returnGame();
        }
    }
}

/*Prints the entire available catalgoue*/
void printCatalogue()
{
    FILE *text_file = fopen(CATALOGUE_LOCATION, "rb+");
    if (!text_file)
    {
        perror("Couldn't open file");
    }
    else
    {
        /*Initialises an empty game to store the values of each game in the catalogue*/
        Game game = {0, "", "", "", 0, false, "", ""};
        /*Prints header*/
        printf("\nVideo Game Catalogue");
        printf("\nCatalogue-Number\tTitle\t\tDeveloper\tPlatform\tYear\tBorrow-Status\tBorrower-Name\tBorrower-Date\n");

        /*Goes through the file and prints only recorded games in the catalogue*/
        while (!feof(text_file))
        {
            int found = fread(&game, sizeof(Game), 1, text_file);
            if (found != 0 && game.id_number != 0)
            {
                printf("%7d\t%24s\t%8s\t%6s\t%12d\t%4d\t%17s\t%11s\n", game.id_number, game.title, game.developer, game.platform, game.year, game.borrowed, game.name_borrower, game.date_borrowed);
            }
        }
        printf("\n");
    }
    fclose(text_file);
}

/*Allows the user to add games to the catalogue*/
void recordCatalogue()
{
    FILE *text_file = fopen(CATALOGUE_LOCATION, "rb+");
    if (!text_file)
    {
        perror("Error creating file");
    }
    else
    {
        /*Initialises a variable of type game with empty types*/
        Game game = {0, "", "", "", 0, false, "", ""};

        /*Recurringly asks users to input games until they're finished*/
        int continueInput = 1;
        while (continueInput == 1)
        {
            /*Asks for the id of the game*/
            printf("\nEnter id number (1-1000): ");
            scanf("%d", &game.id_number);

            /*Asks for the title of the game*/
            printf("Enter the game title: ");
            scanf(" %[^\n]%*c", game.title);

            /*Asks for the developer of the game*/
            printf("Enter the developer name: ");
            scanf(" %[^\n]%*c", game.developer);

            /*Asks for the playform of the game*/
            printf("Enter the platform(PC,Xbox,PS4): ");
            scanf(" %[^\n]%*c", game.platform);

            /*Asks for the year of the game*/
            printf("Enter the year: ");
            scanf("%d", &game.year);

            /*Finds and places the game in its appropriate spot in the file according to its id*/
            fseek(text_file, (game.id_number - 1) * sizeof(Game), SEEK_SET);
            fwrite(&game, sizeof(Game), 1, text_file);

            /*Asks users whether they want to continue adding games to the catalogue*/
            printf("\nIf you want to continue, press 1. Otherwise press any other number: ");
            scanf("%d", &continueInput);

            printf("\n");
        }
        fclose(text_file);
    }
}

/*Allows user to borrow a game by inputting an id number*/
void borrowGame()
{
    FILE *text_file = fopen(CATALOGUE_LOCATION, "rb+");
    if (!text_file)
    {
        perror("Error opening file");
    }
    else
    {
        Game game;
        int id_number;
        /*Asks user the id in order to find the game*/
        printf("What game would you like to borrow(Enter the id number): ");
        scanf("%d", &id_number);

        /*Locates the game according to id number*/
        fseek(text_file, (id_number - 1) * sizeof(Game), SEEK_SET);
        int found = fread(&game, sizeof(Game), 1, text_file);

        /*Allows user to borrow a game only when it exists and it hasn't been borrowed*/
        if (found != 0 && game.borrowed == false)
        {
            /*Asks user for their name and the date*/
            printf("Enter your name: ");
            scanf(" %[^\n]%*c", game.name_borrower);
            printf("Enter the date(dd/mm/year): ");
            scanf(" %[^\n]%*c", game.date_borrowed);

            /*Sets the game as borrowed and rewrites the information into the catalogue*/
            game.borrowed = true;
            fseek(text_file, (id_number - 1) * sizeof(Game), SEEK_SET);
            fwrite(&game, sizeof(Game), 1, text_file);

            printf("\n%s has been successfully borrowed!\n", game.title);
        }
        /*If the game number is 0, it means that it hasn't been initialised*/
        else if (game.id_number == 0)
        {
            printf("\nCouldn't find what you were looking for!\n");
        }
        /*Otherwise it must have been borrowed*/
        else
        {
            printf("\nThe game has already been borrowed!\n");
        }
        fclose(text_file);
    }
}

/*Allows user to return a game by inputting its id number*/
void returnGame()
{
    FILE *text_file = fopen(CATALOGUE_LOCATION, "rb+");
    if (!text_file)
    {
        perror("Error opening file");
    }
    else
    {
        Game game;
        int id_number;
        /*Asks user the id in order to find the game*/
        printf("What game would you like to return(Enter the id number): ");
        scanf("%d", &id_number);

        /*Locates the game according to id number*/
        fseek(text_file, (id_number - 1) * sizeof(Game), SEEK_SET);
        int found = fread(&game, sizeof(Game), 1, text_file);

        /*Allows user to borrow a game only when it exists and it has been borrowed*/
        if (found != 0 && game.borrowed == true)
        {
            /*Resets the name and date of the borrower to empty strings*/
            strcpy(game.name_borrower, "");
            strcpy(game.date_borrowed, "");

            /*Sets the game as unborrowed and rewrites the information into the catalogue*/
            game.borrowed = false;
            fseek(text_file, (id_number - 1) * sizeof(Game), SEEK_SET);
            fwrite(&game, sizeof(Game), 1, text_file);

            printf("\n%s has been successfully returned!\n", game.title);
        }
        /*If the game number is 0, it means that it hasn't been initialised*/
        else if (game.id_number == 0)
        {
            printf("\nCouldn't find what you were looking for\n");
        }
        /*Otherwise it must have been borrowed*/
        else
        {
            printf("\nThe game has already been returned\n");
        }
        fclose(text_file);
    }
}