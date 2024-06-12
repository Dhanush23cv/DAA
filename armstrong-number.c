#include <stdio.h>
#include <math.h>

// Function to calculate the number of digits in a number
int countDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + countDigits(num / 10);
}

// Recursive function to calculate the sum of digits raised to the power of n
int sumOfPowers(int num, int n) {
    if (num == 0)
        return 0;
    int digit = num % 10;
    return pow(digit, n) + sumOfPowers(num / 10, n);
}

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int n = countDigits(num);
    return num == sumOfPowers(num, n);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
