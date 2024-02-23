#include <stdio.h>  //Used for printf()
#include <stdlib.h> //Used for malloc()
#include <string.h> //Used for strlen()

#define AllowedCharacters 255 // define the allowed characters

// Function to find and remove the shortest string
char **findAndRemoveShortestString(char **array)
{
    int shortestStringIndex = 0; // index of the shortest string
    for (int i = 0; i < 5; i++)  // loop through the array
    {
        if (strlen(array[i]) < strlen(array[shortestStringIndex])) // if the current string is shorter than the shortest string
        {
            shortestStringIndex = i; // update the index of the shortest string
        }
    }

    printf("Shortest string removed: %s\n", array[shortestStringIndex]);

    char **newArray = malloc(sizeof(char *) * 4); // allocate memory for 4 strings as its the size of the array after removing the shortest string
    int j = 0;                                    // declare J
    for (int i = 0; i < 5; i++)                   // loop through the array
    {

        if (array[i] != NULL && i != shortestStringIndex) // if the string is not null and not the shortest string index
        {
            newArray[j] = malloc(strlen(array[i]) + 1); // allocate memory for the new array
            strcpy(newArray[j], array[i]);              // copy the string to the new array
            j++;                                        // increment j
        }
    }
    return newArray; // return the new array
}

int main()
{

    char **initialString = malloc(sizeof(char *) * 5); // allocate memory for the 2d array (amount of words)
    for (int i = 0; i < 5; i++)                        // loop through the array
    {
        initialString[i] = malloc(AllowedCharacters * sizeof(char)); // allocate memory for each word
    }

    for (int i = 0; i < 5; i++) // loop through the array
    {
        scanf("%s", initialString[i]); // store the string in the 2d array
    }

    char **newArray = findAndRemoveShortestString(initialString); // call the function to remove the shortest string
    printf("Array after removal:\n");
    for (int i = 0; i < 4; i++) // loop through the new array
    {
        printf("%s\n", newArray[i]);
    }

    for (int i = 0; i < 5; i++) // loop through the initial array
    {
        free(initialString[i]); // free the memory allocated for each word
    }
    free(initialString); // free the memory allocated for the array

    for (int i = 0; i < 4; i++) // loop through the new array
    {
        free(newArray[i]); // free the memory allocated for each word
    }
    free(newArray); // free the memory allocated for the array

    return 0; // return 0 and exit
}