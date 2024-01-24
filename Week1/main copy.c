#include <stdio.h>  //Used for printf()
#include <ctype.h>  //Used for isdigit()
#include <stdlib.h> //Used for atoi()
#include <math.h>   //Used for log2()

int main(int argc, char *argv[]) // main function with arguments
{

    if (argc < 2) // checks if there has been any argument entered
    {
        printf("No Command line argument provided, please provide a number.");
        return 0; // exit program
    }

    for (int i = 0; argv[1][i] != '\0'; i++) // for loop to check if the argument is a digit
    {
        if (isdigit(argv[1][i]) == 0) // checks if its a digit if its false it will return 0
        {
            printf("Please provide a number");
            return 0; // exit program
        }
    }

    int number = atoi(argv[1]);           // converts the argument to an integer
    int result = 0;                       // variable declaration
    int zeroCounter = 0;                  // variable declaration
    int oneCounter = 0;                   // variable declaration
    int maskShifts = log2(atoi(argv[1])); // calculates the number of shifts needed for the mask to fit the number
    int mask = 0b1;                       // mask declaration
    mask = mask << maskShifts;            // shifts the mask to the left by the number of shifts needed
    printf("Number: %d\n", number);
    printf("Binary: ");
    for (int i = 0; i < maskShifts; i++) // for loop to print the binary number
    {
        if (number & mask) // checks if the number and mask are true if so it will print 1
        {
            result = 1;          // assign 1 to result
            oneCounter++;        // increment oneCounter
            if (oneCounter == 1) // checks if oneCounter is 1 if so it will print 0b
            {
                printf("0b");
            }
        }
        else if (oneCounter > 0) // checks if oneCounter is greater than 0 because that means that the first 1 has been printed
        {
            result = 0;    // assign 0 to result
            zeroCounter++; // increment zeroCounter
        }

        if (oneCounter > 0) // checks if oneCounter is greater as the binary should start with 1
        {
            printf("%d", result);
        }
        mask = mask >> 1; // shifts the mask to the right by 1
    }
    printf("\n");
    printf("Number of 0s: %d\n", zeroCounter);
    printf("Number of 1s: %d\n", oneCounter);
}