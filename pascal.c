#include <stdio.h>

// Function to generate and print Pascal's Triangle
void printPascalTriangle(int n) {
    int arr[n][n];

    // Initialize the triangle
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++) {
            // The first and last values in every row are 1
            if (i == 0 || i == line) {
                arr[line][i] = 1;
            } else {
                // Other values are the sum of values just above and to the left of above
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
            }
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input the number of rows for Pascal's Triangle
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Print Pascal's Triangle
    printPascalTriangle(n);

    return 0;
}
