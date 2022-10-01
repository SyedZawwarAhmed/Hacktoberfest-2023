#include <stdio.h>

int main()
{
    //initialization variable
    int month, year, day;
    int total_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    puts("GETTING THE NUMBER OF DAYS");
    puts("IN A MONTH AND A YEAR");
    printf("Enter Month (1-12) : ");
    scanf("%d", &month);
    printf("\nEnter Years : ");
    scanf("%d", &year);

    if(month == 2){
        if(year % 4 == 0){
            day = 29;
        } else {
            day = 28;
        }
    } else {
        day = total_days[month-1];
        printf("\nNumber of days in month %d year %d is %d days\n", month, year, day);
    }
}