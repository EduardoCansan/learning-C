# Structs 🏠

Structures allow you to group different variables into one type.

### Topics Covered
- **Defining a struct**:
    ```c
    struct Person {
        char name[50];
        int age;
    };
<br>

- **Creating variables**:
    ```c
    struct Person p1 = {"Alice", 30};
<br>

- **Accessing members**:
    ```c
    printf("%s is %d", p1.name, p1.age);
### Why It Matters
Structs let you model real-world entities by combining different types into one custom type.