
# Recursion 👥

Recursion is when a function calls itself to solve a problem.

### Topics Covered
- **Basic structure**:
    ```c
    int factorial(int n) {
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }
<br>

- **Base case**: The stopping condition to avoid infinite recursion.

- **Recursive case**: The part that breaks down the problem into smaller pieces.

- **Examples**:
    - Factorial
    - Fibonacci sequence
    - Traversing data structures (like trees)

### Why It Matters
Recursion allows elegant solutions to problems that are naturally repetitive or hierarchical.