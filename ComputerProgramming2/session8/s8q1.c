/*Ashraf Ali - 19315281*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COUNTIES_INPUT "counties.txt" // Location of our county input
#define TOWN_INPUT "towns.txt"        // Location of our town input

struct county
{
    char *longName;

    char *shortName;

    unsigned int population;
};

struct town
{
    char *name;

    unsigned int population;

    struct county aCounty;
};

void readCounties(struct county Counties[4]);                    //Initialises our County array with the information of counties located in a text file
void readTowns(struct town Towns[5], struct county Counties[4]); //Initialises our Town array with the information of towns located in a text file

int main(void)
{
    struct county Counties[4]; //Stores Counties and their respective information
    struct town Towns[5];      //Stores Towns and their respective information

    readCounties(Counties);     //Reads counties from a text file into our counties array
    readTowns(Towns, Counties); //Reads Towns from a text file into our towns array

    /*Outputs a table countaining all the info on each town and their respective county*/
    printf("Town\t\tPopulation\tCounty\t\tAbbrev.\tPopulation Of County");
    for (int i = 0; i < 5; i++)
    {
        printf("\n%-11s\t%u\t\t%s\t\t%s\t%u", Towns[i].name, Towns[i].population, Towns[i].aCounty.longName, Towns[i].aCounty.shortName, Towns[i].aCounty.population);
    }
    printf("\n");

    return 0;
}

/*Initialises our County array with the information of counties located in a text file*/
void readCounties(struct county Counties[4])
{
    /*Opens county text file containing information on counties*/
    FILE *county_input = fopen(COUNTIES_INPUT, "r");

    /*Error checking*/
    if (!county_input)
    {
        perror("Could not locate county input file");
    }
    else
    {
        /*Loops through county array and allocates memory for the string*/
        for (int i = 0; i < 4; i++)
        {
            Counties[i].longName = (char *)calloc(15, sizeof(char));
            Counties[i].shortName = (char *)calloc(3, sizeof(char));
        }
        /*Loops through txt file and reads information on counties*/
        for (int i = 0; i < 4; i++)
        {
            fscanf(county_input, "%s %s %u", Counties[i].longName, Counties[i].shortName, &Counties[i].population);
        }
        fclose(county_input);
    }
}

/*Initialises our Town array with the information of towns located in a text file*/
void readTowns(struct town Towns[5], struct county Counties[4])
{
    /*Opens town text file containing information on each town*/
    FILE *town_input = fopen(TOWN_INPUT, "r");

    /*Error checking*/
    if (!town_input)
    {
        perror("\nCould not locate town input file!\n");
    }
    else
    {
        char temp_county_name[15]; // Temporarily stores the current county being read in
        /*Allocates memory for each town name*/
        for (int i = 0; i < 5; i++)
        {
            Towns[i].name = (char *)calloc(15, sizeof(char));
        }

        /*Loops through txt file and imports a town and its respective information*/
        for (int i = 0; i < 5; i++)
        {
            fscanf(town_input, "%s %u %s", Towns[i].name, &Towns[i].population, temp_county_name);
            /*Compares the temporary county name against all the counties beings stored.*/
            for (int j = 0; j < 4; j++)
            {
                /*If there's a match the county structure will be placed into that respective town*/
                if (strcmp(temp_county_name, Counties[j].longName) == 0)
                {
                    Towns[i].aCounty = Counties[j];
                    break;
                }
            }
        }
        fclose(town_input);
    }
}