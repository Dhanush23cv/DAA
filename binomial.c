#include <stdio.h>

// Function to compute the binomial coefficient C(n, k) using dynamic programming
int binomialCoeff(int n, int k) {
    int C[n+1][k+1];
    int i, j;

    // Initialize all entries as 0
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            C[i][j] = 0;
        }
    }

    // Calculate binomial coefficient using bottom-up approach
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= (i < k ? i : k); j++) {
            // Base case: C(i, 0) = C(i, i) = 1
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                // C(i, j) = C(i-1, j-1) + C(i-1, j)
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    return C[n][k];
}

int main() {
    int n = 5, k = 2;
    printf("C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));
    return 0;
}
