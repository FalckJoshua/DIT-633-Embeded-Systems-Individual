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

void validDayandWeekInput(enum weeks week, enum days_of_the_week today)
{
    if (week < 1 || week > 5)
    {
        printf("invalid week");
        return 0;
    }
    if (today < 1 || today > 7)
    {
        printf("invalid day");
        return 0;
    }
}

void printWeekAndDay(enum weeks week, enum days_of_the_week today)
{
    printf("Week %d, ", week);
    switch (today)
    {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    case 7:
        printf("Sunday\n");
        break;
    }
}

int main()
{
    enum weeks startingWeek = getStartingWeek();
    enum days_of_the_week startingDay = getStartingDay();
    validDayandWeekInput(startingWeek, startingDay);

    for (int i = startingWeek; i < NUMBER_OF_WEEKS; i++)
    {
        for (int j = startingDay; j < NUMBER_OF_DAYS; j++)
        {
            printWeekAndDay(i, j);
            sleep(1);
        }
        startingDay = MONDAY;

    }
}

