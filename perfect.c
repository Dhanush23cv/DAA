#include <stdio.h>

// Recursive function to find the sum of divisors
int sumOfDivisors(int num, int i) {
    // Base case: if i exceeds num/2, stop the recursion
    if (i > num / 2) {
        return 0;
    }
    // Check if i is a divisor of num
    if (num % i == 0) {
        // If i is a divisor, include it in the sum and recurse for next divisor
        return i + sumOfDivisors(num, i + 1);
    } else {
        // If i is not a divisor, move to the next potential divisor
        return sumOfDivisors(num, i + 1);
    }
}

// Function to check if a number is a perfect number
int isPerfectNumber(int num) {
    // Call the sumOfDivisors function starting from 1
    return num == sumOfDivisors(num, 1);
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
