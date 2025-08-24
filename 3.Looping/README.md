# Looping 🔄

Loops allow you to run code repeatedly until a condition changes.

### Topics Covered
- **while loop**: Repeats as long as a condition is true.
  ```c
  while (i < 5) {
      printf("%d\n", i);
      i++;
  }
<br>

- **do while loop**: Runs at least once, then checks the condition.
    ``` c
    do {
        printf("%d\n", i);
        i++;
    } 
    while (i <= 5); 
<br>

- **for loop**: Compact form with initialization, condition, increment.
    ``` c
    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }
<br>

- **Nested loops**: Loops inside loops, useful for working with tables or grids.

- **Control statements**:
    - `break` → exit a loop immediately.
    - `continue` → skip to the next iteration

### Why It Matters
Loops save you from writing repetitive code and are essential for tasks like iterating through arrays, processing data, or performing calculations multiple times.