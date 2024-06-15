#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime using recursion
bool isPrime(int n, int divisor) {
    // Base cases
    if (n <= 2) 
        return (n == 2);
    if (n % divisor == 0) 
        return false;
    if (divisor * divisor > n) 
        return true;

    // Check next divisor
    return isPrime(n, divisor + 1);
}

// Recursive function to print prime numbers in a given range
void printPrimes(int current, int limit) {
    if (current > limit) 
        return;
    if (isPrime(current, 2)) 
        printf("%d ", current);
    printPrimes(current + 1, limit);
}

// Driver code
int main() {
    int limit;

    printf("Enter the limit up to which to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d are: ", limit);
    printPrimes(2, limit);

    return 0;
}
