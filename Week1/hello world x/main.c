#include <stdio.h>
#include <string.h>
#define MAX 50 //define max
#define MIN 3 //define mine

int main (int argc, char * argv[]) {
if (argc < 2) { //checks if there has been any argument entered
    printf("No Command line argument provided, please provide a name.");
    return 0; //exit program 
}
int nameLength = strlen(argv[1]); //assign the length of the argument to nameLength

if (nameLength > MAX) { // compares name length to MAX
    printf("Name too long, max %d characters", MAX);
    return 0; //exit program
}

if (nameLength < MIN) { // compared name length to MIN
    printf("Name too short, min %d  characters", MIN);
    return 0; //exit program
}

printf("\n Hello %s, how is your day today?", argv[1]);

}