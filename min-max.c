#include <stdio.h>

// Function to find the minimum value using recursion
void findMin(int arr[], int size, int index, int *min, int *minIndex) 
{
    if (index == size) 
    {
        return;
    }

    if (arr[index] < *min) 
    {
        *min = arr[index];
        *minIndex = index;
    }

    findMin(arr, size, index + 1, min, minIndex);
}

// Function to find the maximum value using recursion
void findMax(int arr[], int size, int index, int *max, int *maxIndex) 
{
    if (index == size) 
    {
        return;
    }

    if (arr[index] > *max) 
    {
        *max = arr[index];
        *maxIndex = index;
    }

    findMax(arr, size, index + 1, max, maxIndex);
}

int main() 
{
    int n;

    // Input the number of elements
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the list: \n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int min = arr[0], max = arr[0];
    int minIndex = 0, maxIndex = 0;

    // Call the recursive functions to find the minimum and maximum values and their indices
    findMin(arr, n, 0, &min, &minIndex);
    findMax(arr, n, 0, &max, &maxIndex);

    // Print the results
    printf("Minimum value: %d at index %d\n", min, minIndex);
    printf("Maximum value: %d at index %d\n", max, maxIndex);

    return 0;
}
