#include <stdio.h> //Used for printf()
#include <stdlib.h> //Used for atoi()

// Function prototypes
void checkArgumentAndStore(int argc, char *argv[]);

// constants
const int BIT_SIZE[] = {1, 3, 2, 1, 1}; // the size of the bits
const int BIT_MAX_VALUE[] = {1, 7, 3, 1, 1}; // the max value of the bits
int input[5]; // the input array

// Main function
int main(int argc, char *argv[])
{
    checkArgumentAndStore(argc, argv); // call the checkArgumentAndStore function to check if the argument is valid and store the input
    int bitpack = 0; // initialize the bitpack
    for (int i = 0; i < 5; i++) // loop through the input
    {
        bitpack = bitpack << BIT_SIZE[i]; // shift the bitpack to the left
        bitpack = bitpack | input[i];    // add the input to the bitpack
    }
    printf("0x%x\n", bitpack);
}

// Checks if the argument is valid
void checkArgumentAndStore(int argc, char *argv[])
{
    if (argc > 5) // if there are enoguh arguments
    {
        for (int i = 1; i < argc; i++) // loop through the arguments
        {
            int number = atoi(argv[i]);   // convert the argument to an int
            if (number >= 0 && number <= BIT_MAX_VALUE[i-1]) // check so that the number is between 0 and the max value
            {
                input[i - 1] = number;
            }
            else
            {
                printf("invalid \n");
                exit(0); // exit the program
            }
        }
    }
    else
    {
        printf("invalid \n");
        exit(0); // exit the program
    }
}