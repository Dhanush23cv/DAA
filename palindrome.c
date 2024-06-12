#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive function to check if a string is a palindrome
bool isPalindrome(char str[], int start, int end) {
    // Base case: if the start index is greater than or equal to the end index
    if (start >= end) {
        return true;
    }
    
    // Check if the characters at start and end are the same
    if (str[start] != str[end]) {
        return false;
    }
    
    // Recursive case: move towards the middle
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);  // Reading the string input

    int length = strlen(str);

    // Call the recursive function to check for palindrome
    if (isPalindrome(str, 0, length - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
