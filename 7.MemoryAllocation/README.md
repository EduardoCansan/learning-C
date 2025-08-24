# Memory Allocation 💾

Dynamic memory allocation lets programs request memory at runtime. Allocates a block of memory.

### Topics Covered
- **malloc**:
    ```c
    int *arr = (int*) malloc(5 * sizeof(int));
<br>

- **calloc**:
    ```c
    int *arr = (int*) calloc(5, sizeof(int));
<br>

- **malloc**:
  ```c
    int *new_arr = (int*) realloc(arr, 10 * sizeof(int));
<br>

- **calloc**: Like malloc, but initializes all elements to 0.

- **realloc**: Resize an existing memory block.

- **free**: Releases allocated memory.

- **Memory leaks**: Forgetting to free memory wastes resources.

### Why It Matters
Static arrays have fixed size. Dynamic memory lets you create flexible data structures like linked lists, trees, or variable-sized arrays.