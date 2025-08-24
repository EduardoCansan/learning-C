# Pointers 📌

Pointers store the memory addresses of other variables.

### Topics Covered
- **Definition**:
    ```c
    int x = 10;
    int *ptr = &x;
<br>

- **Dereferencing**: Access the value at a pointer’s address.
    ```c
    printf("%d", *ptr); // prints 10
<br>

- **Pointers and arrays**: An array’s name is essentially a pointer to its first element.

- **Pointer arithmetic:** Incrementing moves to the next memory location for the type.

- **Pointers and functions**: Passing by reference allows functions to modify values directly.

### Why It Matters
Pointers give you direct memory control, which is one of C’s most powerful (and tricky) features. They are essential for arrays, dynamic memory, and data structures.