#include <stdio.h>

// Function to print numbers from 1 to n
void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    printNumbers(n - 1);  // Recursive call to print the previous numbers
    printf("%d ", n);     // Print the current number
}

// Function to print the pattern up to n rows
void printPattern(int n, int current) {
    if (current > n) {
        return;  // Base case: when current row exceeds n, stop the recursion
    }
    printNumbers(current);  // Print numbers for the current row
    printf("\n");           // Move to the next line
    printPattern(n, current + 1);  // Recursive call for the next row
}

int main() {
    int n = 4;  // Change this value to print more rows
    printPattern(n, 1);
    return 0;
}
