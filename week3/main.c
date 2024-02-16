#include <stdio.h>  //Used for printf()
#include <stdlib.h> //Used for malloc()

// GLOBAL VARIABLES
int matrix_x; // declare global variable to store the number of rows
int matrix_y; // declare global variable to store the number of columns

// function to prints the matrix
void printMatrix(int **matrix)
{

    for (int i = 0; i < matrix_x; i++) // loop through the rows
    {
        for (int j = 0; j < matrix_y; j++) // loop through the columns
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to add two matrices
void addMatrix(int **matrix1, int **matrix2)
{
    int **result = (int **)malloc(matrix_x * sizeof(int *)); // allocate memory for the result matrix
    for (int i = 0; i < matrix_x; i++)                       // loop through the rows
    {
        result[i] = (int *)malloc(matrix_y * sizeof(int)); // allocate memory for the columns of the result matrix
    }

    for (int i = 0; i < matrix_x; i++) // loop through the rows
    {
        for (int j = 0; j < matrix_y; j++) // loop through the columns
        {
            result[i][j] = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);; // add the elements of the two matrices and store the result in the result matrix
        }
    }
    printf("The sum is:\n");
    printMatrix(result); // call the function to print the result matrix
}

// function to create a matrix
int **matrixMaker()
{
    int **matrix = (int **)malloc(matrix_x * sizeof(int *)); // allocate memory for the matrix
    for (int i = 0; i < matrix_x; i++)                       // loop through the rows
    {
        matrix[i] = (int *)malloc(matrix_y * sizeof(int)); // allocate memory for the columns of the matrix
    }

    for (int i = 0; i < matrix_x; i++) // loop through the rows
    {
        for (int j = 0; j < matrix_y; j++) // loop through the columns
        {
            int integrityCheck = scanf("%d", &matrix[i][j]); // store the input in the matrix and store the return value in integrityCheck
            if (integrityCheck < 1)                          // check if the user inserted a valid integer
            {
                printf("invalid");
                exit (0); // exit the program
            }
        }
    }
    return matrix; // return the matrix
}

// function to scan the size of the matrix
void scanMatrixSize()
{
    scanf("%d", &matrix_x); // store the input in the global variable matrix_x
    scanf("%d", &matrix_y); // store the input in the global variable matrix_y
}

// function to check the size of the matrix
void checkMatrixSize()
{
    if ((matrix_x < 2 || matrix_x > 4) || (matrix_y < 2 || matrix_y > 4)) // check if the size of the matrix is valid
    {
        printf("invalid");
        exit(0); // exit the program
    }
}

// main function
int main()
{
    scanMatrixSize();              // call the function to scan the size of the matrix
    checkMatrixSize();             // call the function to check the size of the matrix
    int **matrix1 = matrixMaker(); // call the function to create the first matrix
    int **matrix2 = matrixMaker(); // call the function to create the second matrix
    addMatrix(matrix1, matrix2);   // call the function to add the two matrices
    return 0;                      // return 0 to exit the program
}
