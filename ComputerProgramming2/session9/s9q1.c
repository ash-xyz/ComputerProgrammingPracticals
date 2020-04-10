/*Ashraf Ali 19315281*/
#include <stdio.h>

struct zip_custs
{
    int zip_code;

    int customer_count;
};

int main(void)
{
    /*Creates our file and returns a pointer to it*/
    FILE *customer_file;
    if (!(customer_file = fopen("customers.dat", "wb+")))
    {
        perror("Couldn't create file");
    }
    else
    {
        /*Input array*/
        int myCustomers[5][2] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22}, {85446, 88}};
        /*An array of zip_custs structs to store our customer info*/
        struct zip_custs customers[5];
        
        /*Initialises our struct array with the customers data*/
        for (int i = 0; i < 5; i++)
        {
            customers[i].zip_code = myCustomers[i][0];       //Adds our zip code
            customers[i].customer_count = myCustomers[i][1]; //Adds our customer count
        }

        /*Writes our array of structs to a .dat file*/
        for (int i = 0; i < 5; i++)
        {
            fwrite(&customers[i], sizeof(struct zip_custs), 1, customer_file);
        }

        /*Rewinds the file pointer to read from the beginning of the file*/
        rewind(customer_file);

        /*Prints out our customer information as a table*/
        printf("Zipcode\tCustomer-Count\n");
        for (int i = 0; i < 5; i++)
        {
            struct zip_custs temp;                                    // Temporary struct to store data
            fread(&temp, sizeof(struct zip_custs), 1, customer_file); // Reads data in from the binary file into our temp struct
            printf("%d\t\t%d\n", temp.zip_code, temp.customer_count); // Prints out data from our temp struct
        }
        fclose(customer_file);
    }
}