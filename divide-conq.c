#include <stdio.h>

// A structure to return multiple values from the function
struct Pair {
    int min;
    int max;
};

// A utility function to find minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// A utility function to find maximum of two integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// This function returns the minimum and maximum values in an array
struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair minmax, mml, mmr;
    int mid;
    
    // If there is only one element
    if (low == high) {
        minmax.min = arr[low];
        minmax.max = arr[low];
        return minmax;
    }
    
    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.min = arr[high];
            minmax.max = arr[low];
        } else {
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }
    
    // If there are more than two elements
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);
    
    // Compare minimums of two parts
    minmax.min = min(mml.min, mmr.min);
    
    // Compare maximums of two parts
    minmax.max = max(mml.max, mmr.max);
    
    return minmax;
}

// Driver code
int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    
    struct Pair minmax = getMinMax(arr, 0, arrSize - 1);
    
    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);
    
    return 0;
}
