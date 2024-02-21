#include <stdio.h>  //Used for printf()
#include <stdlib.h> //Used for malloc()
#include <string.h> //Used for strlen()

#define AllowedCharacters 10000 // define the allowed characters
// Function prototypes

char **monkeyArray(char **array) // Prints the words in the 2d array
{
    int shortestStringIndex = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strlen(array[i]) < strlen(array[shortestStringIndex]))
        {
            shortestStringIndex = i;
        }
    }

    // print the shortest string
    printf("Shortest string removed: %s\n", array[shortestStringIndex]);

    char **newArray = malloc(sizeof(char *) * 4);
    int j = 0;
    for (int i = 0; i < 5; i++)
    {

        if (array[i] != NULL && strcmp(array[i], array[shortestStringIndex]) != 0)
        {
            newArray[j] = malloc(strlen(array[i]) + 1);
            strcpy(newArray[j], array[i]);
            j++;
        }
    }
    return newArray;
}

int main()
{

    char **gorillaString = malloc(sizeof(char *) * 5); // allocate memory for the 2d array (amount of words)
    for (int i = 0; i < 5; i++)
    {
        gorillaString[i] = malloc(AllowedCharacters * sizeof(char)); // allocate memory for each word
    }

    for (int i = 0; i < 5; i++)
    {
        scanf("%s", gorillaString[i]); // store the string in the 2d array
    }

    char **newArray = monkeyArray(gorillaString);
    printf("Array after removal:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", newArray[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        free(gorillaString[i]);
    }
    free(gorillaString);

    for (int i = 0; i < 4; i++)
    {
        free(newArray[i]);
    }
    free(newArray);

    return 0;
}