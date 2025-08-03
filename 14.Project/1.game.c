/*
    Create a simple math game in C where the user is asked to choose a difficulty level when the program starts.
    After that, the program should randomly generate a math operation 
    — limited to addition, subtraction, or multiplication — and ask the user to solve it.

    If the user answers correctly, they earn 1 point to their score.
    Regardless of whether the answer is right or wrong, 
    the user can choose whether they want to continue playing or exit the game.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int difficulty;
    int value1;
    int value2;
    int operation;
    int result;
    
} Calculate;

void play();
void displayInfo(Calculate calculate);
int sum(int answer, Calculate calculate);
int sub(int answer, Calculate calculate);
int mult(int answer, Calculate calculate);

int points = 0;

int main() {

    // Must be called only one time
    srand(time(NULL)); // 

    play();

    return 0;
}

void play() {
    Calculate calculate;
    int difficulty;

    printf("\nEnter the desired difficulty level [1][2][3][4]: ");
    scanf("%d", &difficulty);
    calculate.difficulty = difficulty;

    // Generates a random integer value between 0 and 2 (sum[0], sub[1], mult[2])
    calculate.operation = rand() % 3;

    // easy [0 - 10]
    if(calculate.difficulty == 1) {
        calculate.value1 = rand() % 11;
        calculate.value2 = rand() % 11;
    
    // medium [0 - 100]
    } else if (calculate.difficulty == 2) {
        calculate.value1 = rand() % 101;
        calculate.value2 = rand() % 101;
    
    //hard [0 - 1000]  
    } else if(calculate.difficulty == 3) {
        calculate.value1 = rand() % 1001;
        calculate.value2 = rand() % 1001;
    
    // insane [0 - 10000]
    } else if(calculate.difficulty == 4) {
        calculate.value1 = rand() % 10001;
        calculate.value2 = rand() % 10001;
    
    // impossible [0 - 100000]
    } else {
        calculate.value1 = rand() % 100001;
        calculate.value2 = rand() % 100001;
    }

    int answer;
    printf("Report the answer to the following operation: \n");
    
    if(calculate.operation == 0) {
        printf("%d + %d = ", calculate.value1, calculate.value2);
        scanf("%d", &answer);

        if(sum(answer, calculate)) {
            points += 1;
            printf("\nYou have %d points", points);
        }
    
    } else if(calculate.operation == 1) {
        printf("%d - %d = ", calculate.value1, calculate.value2);
        scanf("%d", &answer);

        if(sub(answer, calculate)) {
            points += 1;
            printf("\nYou have %d points", points);
        }
    
    } else if(calculate.operation == 2) {
        printf("%d x %d = ", calculate.value1, calculate.value2);
        scanf("%d", &answer);

        if(mult(answer, calculate)) {
            points += 1;
            printf("\nYou have %d points", points);
        }       
    
    } else {
        printf("\nOperation is not recognized");
    }

    // Restart game
    printf("\n\nDo you want to continue playing? \n[1] YES \n[0] NO \nOption: ");
    int keep;
    scanf("%d", &keep);

    if(keep) {
        play();
    
    } else {
        printf("\nYou ended up with %d points", points);
        exit(0);
    }
}

void displayInfo(Calculate calculate) {
    char option[25];

    if(calculate.operation == 0) {
        sprintf(option, "Sum");
    
    } else if(calculate.operation == 1) {
        sprintf(option, "Subtract");

    } else if(calculate.operation == 2) {
        sprintf(option, "Multiply");
    
    } else {
        sprintf(option, "***Unknown Operation***");
    }

    printf("Value 1: %d \nValue 2: %d \nValue 3: %d \nOperation: %s", 
            calculate.value1, calculate.value2, calculate.difficulty, option);

}

int sum(int answer, Calculate calculate) {
    int result = calculate.value1 + calculate.value2;
    calculate.result = result;
    int correct = 0; // wrong = 0 

    if(answer == calculate.result) {
        printf("\nCorrect Answer!");
        correct = 1; // correct = 1
    } else {
        printf("\nWrong Answer!");
    }

    return correct;
}

int sub(int answer, Calculate calculate) {
    int result = calculate.value1 - calculate.value2;
    calculate.result = result;
    int correct = 0; // wrong = 0 

    if(answer == calculate.result) {
        printf("\nCorrect Answer!");
        correct = 1; // correct = 1
    } else {
        printf("\nWrong Answer!");
    }

    return correct;
}

int mult(int answer, Calculate calculate) {
    int result = calculate.value1 * calculate.value2;
    calculate.result = result;
    int correct = 0; // wrong = 0 

    if(answer == calculate.result) {
        printf("\nCorrect Answer!");
        correct = 1; // correct = 1
    } else {
        printf("\nWrong Answer!");
    }

    return correct;
}