/*
    Define a structure called Time with the following members: hour, minute, and second.
    Write a program that reads two time values from the user, adds them, and displays the 
    result in a proper time format (e.g. HH:MM:SS).
*/

#include <stdio.h>

struct Time{
    int hour;
    int minute;
    int second;
}; 

int main() {

    struct Time time1, time2, result;
    int i;

    printf("Input the first time (hour minute second): ");
    scanf("%d %d %d", &time1.hour, &time1.minute, &time1.second);

    
    printf("\nInput the second ime (hour minute second): ");
    scanf("%d %d %d", &time2.hour, &time2.minute, &time2.second);
    
    result.second = time1.second + time2.second;
    result.minute = time1.minute + time2.minute + result.second / 60;
    result.hour = time1.hour + time2.hour + result.minute / 60;

    result.minute %= 60;
    result.second %= 60;

    printf("\nResultant Time: %02d:%02d:%02d\n", result.hour, result.minute, result.second);

    return 0;
}