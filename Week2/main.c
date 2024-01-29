#include <stdio.h>  //Used for printf()
#include <stdlib.h> //Used for atoi()
#include <unistd.h> //Used for sleep()
//#include <windows.h> //Used for Sleep()

enum days_of_the_week
{
    MONDAY = 1,    // by declaring the first element as one it will start counting from one instead of zero
    TUESDAY,   // hold value 2
    WEDNESDAY, // hold value 3
    THURSDAY,  // hold value 4
    FRIDAY,    // hold value 5
    SATURDAY,
    SUNDAY,
    NUMBER_OF_DAYS
};

enum weeks
{
    WEEK1 = 1,
    WEEK2,
    WEEK3,
    WEEK4,
    WEEK5,
    NUMBER_OF_WEEKS
};

enum weeks getStartingWeek()
{
    char startWeekString[3];
    scanf("%s", startWeekString);
    enum weeks startingWeek = atoi(startWeekString);
    return startingWeek;
}
enum days_of_the_week getStartingDay()
{
    char startDayString[3];
    scanf("%s", startDayString);
    enum days_of_the_week startingDay = atoi(startDayString);
    return startingDay;
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
    printf("Week: %d, ", week);
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

