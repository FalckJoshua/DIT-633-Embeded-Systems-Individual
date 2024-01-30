#include <stdio.h>  //Used for printf()
#include <stdlib.h> //Used for atoi()
#include <unistd.h> //Used for sleep()

enum days_of_the_week
{
    MONDAY = 1,    // by declaring the first element as one it will start counting from one instead of zero
    TUESDAY,   // because I initialised monday as 1, tuesday will be 2..
    WEDNESDAY, // hold value 3
    THURSDAY,  // hold value 4
    FRIDAY,    // hold value 5
    SATURDAY, // hold value 6
    SUNDAY, // hold value 7
    NUMBER_OF_DAYS // holds value 8 and is used to determine the length of the enum
};

enum weeks
{
    WEEK1 = 1, // by declaring the first element as one it will start counting from one instead of zero
    WEEK2, // because I initialised week1 as 1, week2 will be 2..
    WEEK3, // hold value 3
    WEEK4, // hold value 4
    WEEK5, // hold value 5
    NUMBER_OF_WEEKS // hold value 6 and is used to determine the length of the enum
};

enum weeks getStartingWeek() // function to get the starting week and return it as an enum
{
    char startWeekString[3]; // declare a string to store the input
    scanf("%s", startWeekString); // get the input from the user and store it in the string
    enum weeks startingWeek = atoi(startWeekString); // convert the string to an int and store it in the enum
    return startingWeek;// return the enum
}
enum days_of_the_week getStartingDay() // function to get the starting day and return it as an enum
{
    char startDayString[3]; // declare a string to store the input
    scanf("%s", startDayString); // get the input from the user and store it in the string
    enum days_of_the_week startingDay = atoi(startDayString); // convert the string to an int and store it in the enum
    return startingDay; // return the enum
}

void validDayandWeekInput(enum weeks week, enum days_of_the_week today) // function to check if the input is valid
{
    if (week < 1 || week > 5) // if the week is less than 1 or greater than 5
    {
        printf("invalid week");
        return 0; // return 0
    }
    if (today < 1 || today > 7) // if the day is less than 1 or greater than 7
    {
        printf("invalid day");
        return 0; // return 0
    }
}

void printWeekAndDay(enum weeks week, enum days_of_the_week today) // function to print the week and day
{
    printf("Week %d, ", week);
    switch (today) // switch statement to print the day
    {
    case 1: // if today is 1 print monday
        printf("Monday\n");
        break; // break out of the switch statement
    case 2: // if today is 2 print tuesday
        printf("Tuesday\n");
        break; // break out of the switch statement
    case 3: // if today is 3 print wednesday
        printf("Wednesday\n");
        break; // break out of the switch statement
    case 4: // if today is 4 print thursday
        printf("Thursday\n");
        break; // break out of the switch statement
    case 5: // if today is 5 print friday
        printf("Friday\n");
        break; // break out of the switch statement
    case 6: // if today is 6 print saturday
        printf("Saturday\n");
        break; // break out of the switch statement
    case 7: // if today is 7 print sunday
        printf("Sunday\n");
        break; // break out of the switch statement
    }
}

int main() // main function
{
    enum weeks startingWeek = getStartingWeek(); // get the starting week
    enum days_of_the_week startingDay = getStartingDay(); // get the starting day
    validDayandWeekInput(startingWeek, startingDay); // check if the input is valid if not exit the program

    for (int i = startingWeek; i < NUMBER_OF_WEEKS; i++) // for loop while the week is less than 5 (number of weeeks)
    {
        for (int j = startingDay; j < NUMBER_OF_DAYS; j++) // for loop while the day is less than 7 (number of days)
        {
            printWeekAndDay(i, j);
            sleep(1); // sleep for 1 second before printing the next day
        }
        startingDay = MONDAY; // reset the day to monday after the end of the week

    }
}

