#include <stdio.h>

#define INF 99999  // A large number representing infinity
#define MAX 100    // Maximum number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][MAX], int n) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to implement Floyd's algorithm
void floydWarshall(int graph[][MAX], int n) {
    int dist[MAX][MAX];

    // Initialize the distance matrix with the input graph matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, n);
}

int main() {
    int n;
    int graph[MAX][MAX];

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the graph matrix
    printf("Enter the adjacency matrix (use %d to represent infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Apply Floyd-Warshall algorithm
    floydWarshall(graph, n);

    return 0;
}
