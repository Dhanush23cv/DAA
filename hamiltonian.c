#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to check if the vertex v can be added at index 'pos' in the Hamiltonian path
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if the vertex is adjacent to the previously added vertex
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Recursive function to find Hamiltonian circuit starting from index 'pos'
bool hamiltonianCircuitUtil(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the path, check if there is an edge from the last vertex to the first vertex
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true; // Hamiltonian circuit exists
        } else {
            return false; // No Hamiltonian circuit exists
        }
    }

    // Try different vertices as the next candidate in the Hamiltonian path
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to find Hamiltonian circuit with v added to the path
            if (hamiltonianCircuitUtil(graph, path, pos + 1) == true) {
                return true;
            }

            // If adding vertex v doesn't lead to a solution, backtrack
            path[pos] = -1;
        }
    }

    return false; // No Hamiltonian circuit found
}

// Function to find Hamiltonian circuit in a graph
void hamiltonianCircuit(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) {
        path[i] = -1; // Initialize all vertices as not included in the path
    }

    // Start from vertex 0 (can start from any vertex)
    path[0] = 0;

    // Call the recursive function to find Hamiltonian circuit
    if (hamiltonianCircuitUtil(graph, path, 1) == false) {
        printf("No Hamiltonian circuit exists\n");
        return;
    }

    printf("Hamiltonian circuit exists. The circuit is:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

int main() {
    // Example graph represented as an adjacency matrix
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCircuit(graph);

    return 0;
}
