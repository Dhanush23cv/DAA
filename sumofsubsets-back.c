#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to print the subset with the current elements of the set
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Recursive function to find all subsets with the given sum
void findSubsets(int set[], int n, int subset[], int subsetSize, int sum, int targetSum, int index) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    for (int i = index; i < n; i++) {
        if (sum + set[i] <= targetSum) {
            subset[subsetSize] = set[i];
            findSubsets(set, n, subset, subsetSize + 1, sum + set[i], targetSum, i + 1);
        }
    }
}

// Function to solve the Subset Sum problem
void subsetSum(int set[], int n, int targetSum) {
    int subset[MAX_SIZE];
    findSubsets(set, n, subset, 0, 0, targetSum, 0);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 35;

    printf("Subsets with sum %d:\n", targetSum);
    subsetSum(set, n, targetSum);

    return 0;
}
