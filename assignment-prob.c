#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the number of agents/tasks
#define N 4

// Function to find the minimum cost assignment
void findMinCost(int cost[N][N]);

// A utility function to calculate the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// A utility function to calculate the minimum cost to reach the state
int calculateCost(int cost[N][N], int row, int col, int assigned[]) {
    int min_cost = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (assigned[i] == 0) {
            min_cost = min(min_cost, cost[row][i]);
        }
    }
    return min_cost;
}

// A utility function to print the solution
void printSolution(int assigned[]) {
    printf("The optimal assignment is:\n");
    for (int i = 0; i < N; i++) {
        printf("Agent %d is assigned to task %d\n", i, assigned[i]);
    }
}

// Function to solve the assignment problem using Branch and Bound
void findMinCost(int cost[N][N]) {
    // An array to keep track of the assigned tasks
    int assigned[N] = {0};

    // A variable to store the minimum cost
    int min_cost = INT_MAX;

    // A function to solve the problem recursively
    void solve(int row, int current_cost) 
    {
        if (row == N) 
        {
            if (current_cost < min_cost) 
            {
                min_cost = current_cost;
                printSolution(assigned);
            }
            return;
        }

        for (int i = 0; i < N; i++) {
            if (assigned[i] == 0) {
                assigned[i] = row + 1;
                solve(row + 1, current_cost + cost[row][i]);
                assigned[i] = 0;
            }
        }
    }

    // Start solving from the first row
    solve(0, 0);

    // Print the minimum cost
    printf("The minimum cost is: %d\n", min_cost);
}

int main() {
    // Example cost matrix
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    findMinCost(cost);

    return 0;
}
