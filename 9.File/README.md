# File Handling 📑

File I/O (Input/Output) lets you store and retrieve data from files.

### Topics Covered

- **Modes for opening files for writing**:
    - `w` → (write mode)
    - `wb` → (write binary mode)   
    - `a` → (append mode)
    - `ab` → (append binary mode)
    - `r+` → (write mode)
    - `w+` → (write/read mode)
    - `a+` → (append/read mode)

- **Opening a file**:
    ```c
    FILE *f = fopen("data.txt", "w");
- **Writing to a file**:
    ```c
    fprintf(f, "Hello World\n");
- **Reading from a file**:
    ```c
    fscanf(f, "%s", buffer);
- **Closing a file**:
    ```c
    fclose(f);
- **Error handling**: Always check if f == NULL.

### Why It Matters
Files give your programs persistence—data remains after the program stops.