#include <stdio.h>
#include <stdlib.h>

// Function to insert a number into a sorted list
void insertNumber(int arr[], int *n, int num) {
    int i = *n - 1;
    
    // Move elements of arr[0..n-1], that are greater than num,
    // to one position ahead of their current position
    while (i >= 0 && arr[i] > num) {
        arr[i + 1] = arr[i];
        i--;
    }
    
    // Insert the new number
    arr[i + 1] = num;
    
    // Increment the size of the array
    (*n)++;
}

int main() {
    int n, num, i;
    
    // Read the number of elements in the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    
    // Create an array to store the list elements
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    
    // Read the elements of the list
    printf("Enter the elements of the list (sorted in ascending order):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read the number to be inserted
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);
    
    // Insert the number into the list
    insertNumber(arr, &n, num);
    
    // Print the updated list
    printf("Updated list:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free allocated memory
    free(arr);
    
    return 0;
}
