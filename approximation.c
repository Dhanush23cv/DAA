#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 9999999
#define V 4

// Function to find the minimum vertex not yet included in the tour
int findMinVertex(int weight[], bool visited[]) {
    int minVertex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

// Function to find the minimum spanning tree using the Prim's algorithm
void findMST(int graph[V][V], int parent[]) {
    int weight[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        weight[i] = INF;
        visited[i] = false;
    }

    weight[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int minVertex = findMinVertex(weight, visited);
        visited[minVertex] = true;
        for (int j = 0; j < V; j++) {
            if (graph[minVertex][j] != 0 && !visited[j] && graph[minVertex][j] < weight[j]) {
                weight[j] = graph[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }
}

// Function to find the cost of the minimum spanning tree
int findCost(int graph[V][V]) {
    int parent[V];
    findMST(graph, parent);
    int cost = 0;
    for (int i = 1; i < V; i++) {
        cost += graph[i][parent[i]];
    }
    return cost;
}

// Function to find the optimal cost using an approximation algorithm
int findOptimalCost(int graph[V][V]) {
    return 2 * findCost(graph);
}

int main() {
    // Example adjacency matrix representing the weighted graph
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int optimalCost = findOptimalCost(graph);
    printf("The optimal cost using the approximation algorithm is: %d\n", optimalCost);

    return 0;
}
