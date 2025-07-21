/*
    Write a program that fills two 3x3 matrices with decimal values.
    Then calculate and display the sum, subtraction, multiplication, and division between the two matrices.
*/

#include <stdio.h>
#define SIZE 3

void sumMatrixes(int i, int j);
void subtractMatrixes(int i, int j);
void multiplyMatrixes(int i, int j);
void divisorMatrixes(float i, float j);

int main() {

    int matrixOne[SIZE][SIZE];
    int matrixTwo[SIZE][SIZE];
    int i, j;

    printf("Choose numbers to the [MATRIX 1]\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("Enter the value of the Matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixOne[i][j]);
        }
    }

    printf("\nChoose numbers to the [MATRIX 2]\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("Enter the value of the Matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrixTwo[i][j]);
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {

            printf("\nSum Matrix 1 [%d][%d] & Matrix 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            sumMatrixes(matrixOne[i][j], matrixTwo[i][j]);

            printf("\nSubtract Matrix 1 [%d][%d] & Matrix 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            subtractMatrixes(matrixOne[i][j], matrixTwo[i][j]);

            printf("\nMultiply Matrix 1 [%d][%d] & Matrix 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            multiplyMatrixes(matrixOne[i][j], matrixTwo[i][j]);

            printf("\nDivision Matrix 1 [%d][%d] & Matrix 2 [%d][%d]: ", i + 1, j + 1, i + 1, j + 1);
            divisorMatrixes((float)matrixOne[i][j], (float)matrixTwo[i][j]);

            printf("\n");
        }
    }

    return 0;
}

void sumMatrixes(int i, int j) {
    printf("%d", i + j);
}

void subtractMatrixes(int i, int j) {
    printf("%d", i - j);
}

void multiplyMatrixes(int i, int j) {
    printf("%d", i * j);
}

void divisorMatrixes(float i, float j) {
    if (j == 0) {
        printf("Invalid division by 0!");
    } else {
        printf("%.2f", i / j);
    }
}
