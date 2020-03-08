/*Ashraf Ali - 19315281 - 12/02/2020*/
#include <stdio.h>
#include <stdlib.h>
int **generateMatrix(int sizeOfRow, int sizeOfCol);                                                                /*Prompts the user to enter the values of a Matrix and returns the matrix as a 2D array*/
void printMatrix(int **matrix, int rowSize, int columnSize);                                                       /* Prints the 2D matrix*/
int **matrixProduct(int **matrixA, int sizeOfRowA, int sizeOfColA, int **matrixB, int sizeOfRowB, int sizeOfColB); /*Returns a matrix that is the product of A and B, AB*/

int main(void)
{
    int sizeOfRowA;
    int sizeOfRowB;
    int sizeOfColA;
    int sizeOfColB;

    printf("This is a program that multiplies the first matrix, A, by the second matrix, B.\n");
    /*Enters the Dimensions of the first matrix*/
    printf("Please enter the dimensions of the first matrix: \n");
    printf("Size of rows: ");
    scanf("%d", &sizeOfRowA);
    printf("Size of Columns: ");
    scanf("%d", &sizeOfColA);

    /*Enters the Dimensions of the second matrix*/
    printf("\nPlease enter the dimensions of the second matrix: \n");
    printf("Size of rows: ");
    scanf("%d", &sizeOfRowB);
    printf("Size of Columns: ");
    scanf("%d", &sizeOfColB);

    /*Checks whether the matrices can be multiplied, if they can't it'll prompt them to enter it again*/
    while (sizeOfColA != sizeOfRowB)
    {
        printf("Error, please enter matrices of that can be multiplied!\n");
        /*Enters the Dimensions of the first matrix*/
        printf("Please enter the dimensions of the first matrix: \n");
        printf("Size of rows: ");
        scanf("%d", &sizeOfRowA);
        printf("Size of Columns: ");
        scanf("%d", &sizeOfColA);

        /*Enters the Dimensions of the second matrix*/
        printf("\nPlease enter the dimensions of the second matrix: \n");
        printf("Size of rows: ");
        scanf("%d", &sizeOfRowB);
        printf("Size of Columns: ");
        scanf("%d", &sizeOfColB);
        return 0;
    }

    /*Asks user for the content of Matrix A*/
    printf("Enter the contents of matrix A:\n");
    int **matrixA = generateMatrix(sizeOfRowA, sizeOfColA);
    /*Asks user for the contentns of Matrix B*/
    printf("Enter the contents of matrix B:\n");
    int **matrixB = generateMatrix(sizeOfRowB, sizeOfColB);

    /*Prints the contents of Matrix A*/
    printf("The contents of Matrix A: \n");
    printMatrix(matrixA, sizeOfRowA, sizeOfColA);

    /*Prints the contents of Matrix B*/
    printf("The contents of Matrix B: \n");
    printMatrix(matrixB, sizeOfRowB, sizeOfColB);

    /*Multiplies Matrix A by Matrix B and returns the multiple*/
    int **productOfMatrices = matrixProduct(matrixA, sizeOfRowA, sizeOfColA, matrixB, sizeOfRowB, sizeOfColB);
    printf("The product of Matrix A and Matrix B is: \n");
    printMatrix(productOfMatrices, sizeOfRowA, sizeOfColB);

    /*Frees the malloced memory*/
    free(matrixA);
    free(matrixB);
    free(productOfMatrices);

    return 0;
}

/*Prompts the user to enter the values of a Matrix and returns the matrix as a 2D array*/
int **generateMatrix(int sizeOfRow, int sizeOfCol)
{
    /*Creates a 2D array of pointers*/
    int **matrix = (int **)malloc(sizeof(int *) * sizeOfRow);
    for (int i = 0; i < sizeOfRow; i++)
    {
        /*Creates a column along each row*/
        matrix[i] = (int *)malloc(sizeof(int) * sizeOfCol);

        /*Prompts user to enter the value of each cell in the matrix*/
        for (int j = 0; j < sizeOfCol; j++)
        {
            printf("Enter matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
    return matrix;
}
/*Prints the contents of a 2D Array*/
void printMatrix(int **matrix, int rowSize, int columnSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < columnSize; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*Returns a matrix that is the product of A and B, AB*/
int **matrixProduct(int **matrixA, int sizeOfRowA, int sizeOfColA, int **matrixB, int sizeOfRowB, int sizeOfColB)
{
    /*Creates a 2d array of pointers to store our array in*/
    int **productOfMatrices = (int **)malloc(sizeof(int *) * sizeOfRowA);

    /*Follows the matrix rules for multiplying*/
    for (int i = 0; i < sizeOfRowA; i++)
    {
        productOfMatrices[i] = (int *)malloc(sizeof(int) * sizeOfColB);
        for (int j = 0; j < sizeOfColB; j++)
        {
            productOfMatrices[i][j] = 0;
            for (int k = 0; k < sizeOfColA; k++)
            {
                productOfMatrices[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return productOfMatrices;
}