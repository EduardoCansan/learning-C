/*
    Store your age in a variable called age. The program should read this variable and, based on its value, 
    determine whether you are a child, teenager, adult, or senior.
*/

#include <stdio.h>

int main()  {

    int age = 15;

    if (age > 0 && age <= 13  ) {
        printf("You are a child!");
    }
    else if (age >= 14 && age <= 18) {
        printf("You are a teenager!");
    }
    else if (age >= 19 && age <= 59) {
        printf("You are an adult!");
    }
    else if (age >= 60 && age <= 130) {
        printf("You are a senior!");
    }
    else {
        printf("Must be an error in your age...");
    }

    return 0;
}
