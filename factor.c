#include <stdio.h>

// Recursive function to find and print all factors of n
void findFactors(int n, int i) {
    // Base case: if i exceeds n, return
    if (i > n) {
        return;
    }

    // If i is a factor of n, print it
    if (n % i == 0) {
        printf("%d ", i);
    }

    // Recursive call to the next number
    findFactors(n, i + 1);
}

int main() {
    int n;

    // Read the number from the user
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Print the factors of n
    printf("Factors of %d are: ", n);
    findFactors(n, 1);

    return 0;
}
