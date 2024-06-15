#include <stdio.h>
#include <stdlib.h>

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int weights[], int values[], int n) {
    int i, w;
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        K[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    int result = K[n][W];

    // Print the items included in the knapsack
    w = W;
    printf("Items included in the knapsack are:\n");
    for (i = n; i > 0 && result > 0; i--) {
        if (result == K[i - 1][w]) {
            continue;
        } else {
            printf("Item %d (Weight: %d, Value: %d)\n", i, weights[i - 1], values[i - 1]);
            result -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    // Free allocated memory
    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);

    return K[n][W];
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *values = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int max_value = knapsack(W, weights, values, n);
    printf("The maximum value that can be put in the knapsack is: %d\n", max_value);

    // Free allocated memory
    free(values);
    free(weights);

    return 0;
}
