/*
    Create a struct called Vector that contains the fields: float x, float y, and float z.
    Then, declare a variable of this struct, fill it with values, and calculate the sum of the components.
    Print the result of the vector sum.
*/

#include <stdio.h>

typedef struct{
    float x;
    float y;
    float z;
} Vector; 

int main()
{

    int i;

    Vector vector[2];

    printf("Defining values to Vectors: \n");

    for (i = 0; i < 2; i++) {
        printf("\n(%d) Choose a value to X: ", i + 1);
        scanf("%f", &vector[i].x);
        printf("(%d) Choose a value to Y: ", i + 1);
        scanf("%f", &vector[i].y);
        printf("(%d) Choose a value to Z: ", i + 1);
        scanf("%f", &vector[i].z);
    }

    // Vector in array[2] is equal to the sum of vector[0] and vector[1]
    vector[2].x = vector[0].x + vector[1].x;
    vector[2].y = vector[0].y + vector[1].y;
    vector[2].z = vector[0].z + vector[1].z;

    printf("\nSum of Vectors: ");
    printf("\nVector X => %.2f + %.2f = %.2f", vector[0].x, vector[1].x, vector[2].x);
    printf("\nVector Y => %.2f + %.2f = %.2f", vector[0].y, vector[1].y, vector[2].y);
    printf("\nVector Z => %.2f + %.2f = %.2f", vector[0].z, vector[1].z, vector[2].z);

    return 0;

}