# Arrays 🔢

Arrays let you store multiple values in a single variable.

### Topics Covered
- **Definition**:
  ```c
  int numbers[5] = {10, 20, 30, 40, 50};
- **Accessing elements**: Use indexes starting at 0.
  ```c
  printf("%d", numbers[0]); // prints 10
- **Changing values**:
  ```c
  numbers[2] = 100;
- **Iterating with loops**:
  ```c
  for (int i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
  }
- **Multidimensional arrays**:
    ```c
    int matrix[2][2] = {{1,2}, {3,4}};
### Why It Matters
Arrays are the first step into structured data, letting you handle collections of values (like scores, names, or numbers) efficiently.