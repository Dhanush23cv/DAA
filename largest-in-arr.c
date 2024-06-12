#include <stdio.h>

// Recursive function to find the largest element in an array
int findLargest(int arr[], int n) {
    // Base case: if the array has only one element, return that element
    if (n == 1) {
        return arr[0];
    }

    // Recursive step: find the largest element in the rest of the array
    int max = findLargest(arr, n - 1);

    // Compare the last element with the largest element found so far
    if (arr[n - 1] > max) {
        return arr[n - 1];
    } else {
        return max;
    }
}

int main() {
    int n;

    // Prompt user to enter the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the largest element in the array
    int largest = findLargest(arr, n);

    // Print the largest element
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}
