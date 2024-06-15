#include <stdio.h>

// Function to reverse a number using recursion
int reverseNumber(int num, int reversed) {
    // Base case: if the number becomes 0, return the reversed number
    if (num == 0) {
        return reversed;
    }
    // Recursive case: extract the last digit and add it to the reversed number
    reversed = reversed * 10 + (num % 10);
    return reverseNumber(num / 10, reversed);
}

int main() {
    int num, reversed;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    reversed = reverseNumber(num, 0);

    printf("Reversed number: %d\n", reversed);

    return 0;
}
