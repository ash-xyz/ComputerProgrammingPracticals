#include <stdio.h> //include lib for file processing
#include <string.h>

int day, cost, sales, team;                                      //ints to hold values from file
char manager[30];                                                //char arry to hold managers name from file
int dayArray[10], costsArray[10], salesArray[10], teamArray[10]; //arrays to hold the file values
char managerArray[20][10];                                       //array to hold managers' names

char *maxManager();                 //function prototype for you to implement
int maxDayProfit();                 //function prototype for you to implement
int totalSalesManager(char *num);   //function prototype for you to implement
int totalSalesTeam(int teamNumber); //function prototype for you to implement
int readAndLoad();                  //function prototype for readAndLoadFile

int readAndLoad()
{
    FILE *fp; //file pointer

    fp = fopen("test.txt", "r"); //open the file for reading

    //read the first line
    int lineCounter = 0; //line counter to control array positions
    fscanf(fp, "%d %d %d %s %d", &day, &cost, &sales,
           managerArray[lineCounter], &team); //read from the  file and store
    dayArray[lineCounter] = day;              //add day to global array
    costsArray[lineCounter] = cost;           //add costs global to array
    salesArray[lineCounter] = sales;          //add sales to global array
    teamArray[lineCounter] = team;            //add team to global array
    lineCounter++;                            //increment line counter

    //read the remaining line
    while (!feof(fp)) //while not at the end of the file
    {
        fscanf(fp, "%d %d %d %s %d", &day, &cost, &sales,
               managerArray[lineCounter], &team); //read from the  file and store
        dayArray[lineCounter] = day;              //add day to global array
        costsArray[lineCounter] = cost;           //add costs global to array
        salesArray[lineCounter] = sales;          //add sales to global array
        teamArray[lineCounter] = team;            //add team to global array
        lineCounter++;                            //increment line counter
    }
    return 0;
}
char *maxManager()
{
    int maxprofitid = 0;
    for (int i = 0; i < 10; i++)
    {
        if (salesArray[maxprofitid] - costsArray[maxprofitid] < salesArray[i] - costsArray[i])
        {
            maxprofitid = i;
        }
    }
    return managerArray[maxprofitid];
}
int maxDayProfit()
{
    int maxprofitid = 0;
    for (int i = 0; i < 10; i++)
    {
        if (salesArray[maxprofitid] - costsArray[maxprofitid] < salesArray[i] - costsArray[i])
        {
            maxprofitid = i;
        }
    }
    return dayArray[maxprofitid];
}
int totalSalesManager(char *num)
{
    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(managerArray[i], num) == 0)
        {
            total += salesArray[i];
        }
    }
    return total;
}
int totalSalesTeam(int teamNumber)
{
    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        if (teamArray[i] == teamNumber)
        {
            total += salesArray[i];
        }
    }
    return total;
}

int main()
{
    readAndLoad();
    printf("%d\n", totalSalesManager("Dunne"));
}