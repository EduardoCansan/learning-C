/*
    This simple program demonstrates how to use a pointer to a struct in C to update its values.

    We define a Person structure with two members: a name (string) and an age (integer).
    In the main() function, we declare a variable of this struct, and then use a function
    called updateStruct() to change the age using a pointer.

    The program ends by printing the updated age to the screen.
*/

#include <stdio.h>

struct Person {
    char name[64];
    int age;
};

void updateStruct(struct Person *p, int age)
{
    p->age = age;
}

int main() {
    struct Person lowlelvellearning;
    updateStruct(&lowlelvellearning, 20);

    printf("Idade: %d\n", lowlelvellearning.age); 
}
