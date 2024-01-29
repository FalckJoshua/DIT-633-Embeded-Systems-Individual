#include <stdio.h> //Used for printf()
// #include <unistd.h> //Used for sleep()
#include <windows.h> //used for sleep

enum days_of_the_week
{
    MONDAY, // by declaring the first element as one it will start counting from one instead of zero
    TUESDAY,    // hold value 2
    WEDNESDAY,  // hold value 3
    THURSDAY,   // hold value 4
    FRIDAY,     // hold value 5
    SATURDAY,
    SUNDAY,
    NUMBER_OF_DAYS
};

enum weeks
{
    WEEK1,
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
    printf("Provide Starting week: ");
    enum weeks startingWeek = getStartingWeek();

    printf("Provide Starting day: ");
    enum days_of_the_week startingDay = getStartingDay();


    for (int i = startingWeek; i <= NUMBER_OF_WEEKS; i++)
    {
        for (int j = startingDay; j <= NUMBER_OF_DAYS; j++)
        {
            printWeekAndDay(i, j);
            Sleep(1000);
        }
    }
}



