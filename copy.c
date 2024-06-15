#include <stdio.h>

// Function to copy string using recursion
void copyString(char *source, char *destination) 
{
    // Base case: If end of the source string is reached
    if (*source == '\0') 
    {
        *destination = '\0';  // Append null character at the end of destination string
        return;
    }

    // Copy current character from source to destination
    *destination = *source;

    // Recursive call to copy the next character
    copyString(source + 1, destination + 1);
}

int main() 
{
    char source[100], destination[100];

    // Input the source string from the user
    printf("Enter the source string: ");
    scanf("%99s",source);

    // Call the copyString function
    copyString(source, destination);

    // Print the copied string
    printf("Copied string: %s\n", destination);

    return 0;
}
