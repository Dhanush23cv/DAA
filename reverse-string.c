#include <stdio.h>

// Function to print the reverse of a string using recursion
void reverseString(char *str) 
{
    // Base case: If the end of the string is reached
    if (*str == '\0') 
    {
        return;
    }

    // Recursive call to process the next character in the string
    reverseString(str + 1);

    // Print the current character after the recursive call
    printf("%c", *str);
}

int main() 
{
    char str[100];

    // Input the string from the user
    printf("Enter a string: ");
    scanf("%99s",str);
    
    // Call the reverseString function
    printf("Reversed string: ");
    reverseString(str);
    printf("\n");

    return 0;
}
