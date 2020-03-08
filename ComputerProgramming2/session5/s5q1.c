/*Ashraf Ali - 19315281 - 25/02/2020*/
#include <stdio.h>
#include <string.h>
const char *INPUT_TEXT_FILE = "./myFile.txt";       //location of the input file
const char *OUTPUT_TEXT_FILE = "./myOtherFile.txt"; //Locates where it's going to put the output file

int main(void)
{
    FILE *input = fopen(INPUT_TEXT_FILE, "r");   //Searches for a file specified above, to take input from
    FILE *output = fopen(OUTPUT_TEXT_FILE, "w"); //Creates or overwrites a file in the location specified above

    /*Error handling*/
    if (!input)
    {
        perror("File Could not be open");
    }
    if (!output)
    {
        perror("Output file couldn't be created");
    }
    /*Loops through the input file and writes data into the output only if certain conditions are met*/
    else
    {
        /*Terminates once the end of the file is hit*/
        while (!feof(input))
        {
            char city[20];        //Stores the name of the city
            char name[20];        //Stores the persons name
            unsigned phoneNumber; //Stores their phone number
            int age;              //Stores their age
            int consent;          //Stores whether or not a person agreed to share their data

            /*Reads the data of the current line into the variables above*/
            fscanf(input, "%s\t%s\t%u\t%d\t%d", city, name, &phoneNumber, &age, &consent);

            /*Only writes their data into the output file, if they're from Dublin AND consented to sharing their data */
            if (strcmp(city, "Dublin") == 0 && consent == 1)
            {
                fprintf(output, "%s\t%s\t%u\t%d\t%d\n", city, name, phoneNumber, age, consent);
            }
        }
    }

    /*Closes the input and output file*/
    fclose(input);
    fclose(output);

    return 0;
}