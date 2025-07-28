/*
    Write a program that stores data for 5 people using a struct. 
    The struct should contain: char name[120], char email[75], int age, float salary

    Read the data for all 3 people, then display the results with the following logic:

    Conditions:
    If the person is older than 18, print a message saying they are eligible to get a driver’s license.

    If the person's monthly salary is above 8,000.00, print a message saying they are eligible for vehicle financing.
    They can commit up to 35% of their salary as a monthly payment.

    Calculations:
    Calculate the maximum installment amount (35% of salary).

    Then, calculate the maximum financing amount possible, based on 48 monthly payments:
    max_financing = max_installment × 48

    Print the total amount available for financing. 	 
*/

#include <stdio.h>

typedef struct {
    char name[120];
    char email[75];
    int age;
    float salary;
} Person;

void printPersonData(Person person) {

    printf("Name: %s \n", person.name);
    printf("Email: %s \n", person.email);
    printf("Age: %d \n", person.age);
    printf("Salary: %.2f \n", person.salary);

    // Check if is legal to drive
    if (person.age >= 18) {
        printf("You are eligible to get a driver's license\n");
    }
    else {
        printf("You are not eligible to get a driver's license\n");
    }

    // Check if you can finance a car and maximum financing
    float financeValue = person.salary * 0.35; 
    float financingMaximo = financeValue * 48;

    if (person.salary >= 8000) {
        printf("Are you eligible to finance a vehicle, the cost for this is: %.2f", financeValue);
        printf("\nThe maximum possible financing is: %.2f \n", financingMaximo);
    }
    else {
        printf("You cannot finance a vehicle\n");
    }

    printf("\n");

}

int main() {

    int i;
    int size = 3;

    Person person[size];

    // Fill Person Data
    for (i = 0; i < size; i++)
    {
        printf("Digit the name of person %d: ", (i + 1));
        fflush(stdin);
        scanf("%s", &person[i].name);

        printf("Digit the age of person %d: ", (i + 1));
        fflush(stdin);
        scanf("%d", &person[i].age);

        printf("Digit the email of person %d: ", (i + 1));
        fflush(stdin);
        scanf("%s", &person[i].email);

        printf("Digit the salary of person %d: ", (i + 1));
        fflush(stdin);
        scanf("%f", &person[i].salary);

        printf("\n");
    }

    // Looping to print info
    for (i = 0; i < size; i++) {
        printPersonData(person[i]);
    }

    // End the program
    printf("\nType any character to terminate the program: ");
    getch();
    return(0);

}