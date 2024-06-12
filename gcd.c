#include <stdio.h>

// Recursive function to find the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    // Base case: when the second number becomes 0
    if (b == 0) {
        return a;
    }
    // Recursive call with b and the remainder of a divided by b
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    int result = gcd(num1, num2);

    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
