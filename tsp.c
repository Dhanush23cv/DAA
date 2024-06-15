#include <stdio.h>
#include <limits.h>

#define MAX 20  // Adjust this value based on the expected number of cities
#define INF INT_MAX

int n;  // Number of cities
int dist[MAX][MAX];  // Distance matrix
int dp[1 << MAX][MAX];  // DP table for memoization

// Function to find the minimum cost to visit all cities
int tsp(int mask, int pos) {
    // If all cities have been visited, return to the starting city
    if (mask == ((1 << n) - 1)) {
        return dist[pos][0];
    }

    // If the result is already computed, return it
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Visit all the unvisited cities and take the minimum cost
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    // Store the result in the DP table and return it
    return dp[mask][pos] = ans;
}

int main() {
    // Read the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Read the distance matrix
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // Initialize the DP table with -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP from the first city with a mask indicating the first city is visited
    int result = tsp(1, 0);

    // Print the result
    printf("The minimum cost to visit all cities is: %d\n", result);

    return 0;
}
