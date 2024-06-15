#include <stdio.h>

// Function to find the sum of digits of a number
int sumOfDigits(int num) {
    // Base case: if the number is 0, return 0
    if (num == 0) {
        return 0;
    }
    // Recursive case: find the sum of digits of the remaining number and add the last digit
    return (num % 10) + sumOfDigits(num / 10);
}

int main() {
    int num;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate the sum of digits using the recursive function
    int sum = sumOfDigits(num);

    // Print the result
    printf("Sum of digits of %d is %d\n", num, sum);

    return 0;
}
