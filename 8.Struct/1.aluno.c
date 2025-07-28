/*
    Create a struct called Student that contains the following fields:
        name[50]
        registration[10] (e.g. student ID)
        subject[50]

    Then, declare a variable (or an array) of type Student and use a loop to input data for each student.
    At the end, print out all the information collected.
    */

#include <stdio.h>
#define SIZE 2

int i;

// Creating a Struct of Student
typedef struct {
    char name[50];
    char registration[10];
    char subject[50];
} Student;

int main() {

    Student aluno[SIZE];

    printf("Students Data:");

    for (i = 0; i < SIZE; i++) {
        printf("\nStudent %d Name: ", i + 1);
        fgets(aluno[i].name, sizeof(aluno[i].name), stdin);

        printf("Student %d Registration: ", i + 1);
        scanf(aluno[i].registration, sizeof(aluno[i].registration), stdin);
        
        printf("Student %d Subject: ", i + 1);
        scanf(aluno[i].subject, sizeof(aluno[i].subject), stdin);
    }

    printf("\n[DATAS]: \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("\nName Student %d : %s", i+1, aluno[i].name);
        printf("\nRegistration Student %d: %s", i+1, aluno[i].registration);
        printf("\nSubject Student %d: %s\n", i+1, aluno[i].subject);
    }

    return 0;
}