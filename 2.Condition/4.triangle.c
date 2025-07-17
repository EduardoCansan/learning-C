/*
    Write a C program to check whether a triangle is Equilateral, Isosceles or Scalene.
*/

#include <stdio.h>

int main()  {
    
    int sideOne = 15;
    int sideTwo = 15;
    int sideThree = 15;

    if ((sideOne + sideTwo > sideThree) && (sideOne + sideThree > sideTwo) && (sideTwo + sideThree > sideOne)) {

        if (sideOne == sideTwo && sideTwo == sideThree) {
            printf("The triangle is Equilateral! [%d, %d, %d]", sideOne, sideTwo, sideThree);
        
        } else if (sideOne != sideTwo && sideTwo != sideThree && sideOne != sideThree) {
            printf("The triangle is Scalene! [%d, %d, %d]", sideOne, sideTwo, sideThree);
        
        } else {
            printf("The triangle is Isosceles! [%d, %d, %d]", sideOne, sideTwo, sideThree);
        }

    } else {
        printf("The given sides do not form a valid triangle.\n");
    }


    return 0;
}
