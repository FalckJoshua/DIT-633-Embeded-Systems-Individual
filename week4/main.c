#include <stdio.h>  //Used for printf()
#include <stdlib.h> //Used for malloc()
#include <string.h> //Used for strlen() and strcpy()

// Global variables
int argumentSize = 0;       // initialize argumentSize
int permutationCounter = 0; // initialize permutationCounter

// Function prototypes
void swap(char *a, char *b);                                            // Swaps the values of two pointers
void printStringArray(char **array, int rows, int cols);                // Prints the words in the 2d array
void permuteString(char *array, int start, int end, char **largeArray); // Performs the permutation of the string
int sizeFactorial(int size);                                            // Calculates the factorial of the size of the string used for knowing the ammount of words needed.
void checkArgument(int argc, char *argv[]);                             // Checks if the argument is valid

// Main function
int main(int argc, char *argv[])
{
    checkArgument(argc, argv); // call the checkArgument function to check if the argument is valid
    char *array = argv[1];     // store the first argument in the array

    // make 2d array to hold all the words
    int AmmountOfStrings = sizeFactorial(argumentSize);                     // call the sizeFactorial function to get the ammount of words needed
    char **largeArray = (char **)malloc(AmmountOfStrings * sizeof(char *)); // allocate memory for the 2d array
    for (int i = 0; i < AmmountOfStrings; i++)                              // allocate memory for each word
    {
        largeArray[i] = malloc((argumentSize + 1) * sizeof(char)); // allocate memory and +1 for the null terminator
    }

    permuteString(array, 0, argumentSize - 1, largeArray); // call the permute function and store the words in the 2d array
    printf("All permutations of the string %s are: ", array);
    printStringArray(largeArray, AmmountOfStrings, argumentSize + 1); // call the printStringArray function to print the words in the 2d array


    // free the memory
    for (int i = 0; i < AmmountOfStrings; i++) // loop through the 2d array rows
    {
        free(largeArray[i]); // free the memory
        largeArray[i] = NULL; // set the pointer to NULL
    }
    free(largeArray); // free the memory
    largeArray = NULL; // set the pointer to NULL

    return 0;
}

// Function definitions

// Performs the permutation of the string
void permuteString(char *array, int start, int end, char **largeArray) //
{
    if (start == end) // if start is equal to end then store the word in the 2d array
    {
        strcpy(largeArray[permutationCounter], array); // store the word in the 2d array
        permutationCounter++;                          // increment the permutationCounter
    }
    else
    {
        for (int i = start; i <= end; i++) // loop through the string
        {
            swap((array + start), (array + i));               // swap the values of the pointers
            permuteString(array, start + 1, end, largeArray); // call the permute function recursively
            swap((array + start), (array + i));               // swap the values of the pointers
        }
    }
}

// Calculates the factorial of the size of the string used for knowing the ammount of words needed.
int sizeFactorial(int size)
{
    int result = 1;                 // initialize result
    for (int i = 1; i <= size; i++) // loop through the size
    {
        result = result * i; // calculate the factorial
    }
    return result; // return the result
}

// Prints the words in the 2d array
void printStringArray(char **array, int rows, int cols)
{
    for (int i = 1; i < rows; i++) // loop through the 2d array rows
    {
        for (int j = 0; j < cols; j++) // loop through the 2d array columns
        {
            printf("%c", array[i][j]);
        }
        printf(" ");
    }
}

// Swaps the values of two pointers
void swap(char *a, char *b)
{
    char temp = *a; // store the value of a in temp
    *a = *b;        // store the value of b in a
    *b = temp;      // store the value of temp in b
}

// Checks if the argument is valid
void checkArgument(int argc, char *argv[])
{
    if (argc > 1) // if there is an argument
    {

        argumentSize = strlen(argv[1]); // store the size of the argument in argumentSize
        if (argumentSize > 10)          // if the size of the argument is greater than 10
        {
            printf("invalid array to big\n");
            exit(0); // exit the program
        }

    }
    else
    {
        printf("invalid No arguments were passed\n");
        exit(0); // exit the program
    }
}