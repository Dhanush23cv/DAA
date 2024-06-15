#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices in the graph

// Function to check if it is safe to color the vertex 'v' with color 'c'
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;  // All vertices are colored
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color c to vertex v

            // Recur to assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // Backtrack: If assigning color c to vertex v doesn't lead to a solution, remove it
            color[v] = 0;
        }
    }

    return false;  // No color can be assigned to vertex v
}

// Function to solve the graph coloring problem
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;  // Initialize color of all vertices as 0 (not colored)
    }

    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist\n");
        return;
    }

    printf("Solution exists. The coloring of vertices is:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int main() {
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};
    int m = 3; // Number of colors available

    graphColoring(graph, m);

    return 0;
}
