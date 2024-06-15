#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to find the optimal cost of the BST
int optimalBST(int keys[], int freq[], int n) {
    // cost[i][j] will store the optimal cost of BST that can be built from keys[i] to keys[j]
    int cost[n][n];

    // Initialize the table with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = 0;
        }
    }

    // Cost for a single key is equal to its frequency
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // Now we need to consider chains of length 2, 3, ... , n
    for (int L = 2; L <= n; L++) {  // L is the chain length
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                // c = cost when keys[r] becomes root of the subtree
                int c = ((r > i) ? cost[i][r-1] : 0) +
                        ((r < j) ? cost[r+1][j] : 0) +
                        sum(freq, i, j);

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n-1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    printf("Cost of Optimal BST is %d\n", optimalBST(keys, freq, n));
    return 0;
}
