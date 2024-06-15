#include <stdio.h>

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) 
        {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        // If target is smaller, ignore the right half
        else 
        {
            high = mid - 1;
        }
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    // Input the target value to be searched
    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Call binarySearch function
    int result = binarySearch(arr, n, target);

    // Print the result
    if (result != -1) 
    {
        printf("Element found at index %d\n", result);
    } 
    else 
    {
        printf("Element not found in the array\n");
    }

    return 0;
}
