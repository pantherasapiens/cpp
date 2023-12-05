#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int V;          // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph createGraph(int vertices) {
    Graph graph;
    graph.V = vertices;

    // Initialize the adjacency matrix
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph.adjMatrix[i][j] = 0; // Initialize all elements to 0
        }
    }

    return graph;
}

void addEdge(Graph *graph, int v, int w) {
    graph->adjMatrix[v][w] = 1;
    graph->adjMatrix[w][v] = 1; // Assuming an undirected graph
}

void greedyColoring(Graph *graph) {
    int result[MAX_VERTICES]; // Initialize all vertices as unassigned
    int availableColors[MAX_VERTICES];

    // Assign the first color to the first vertex
    result[0] = 0;
    availableColors[0] = 1;

    // Process the remaining vertices
    for (int u = 1; u < graph->V; u++) {
        // Initialize the available colors for the current vertex
        for (int i = 0; i < graph->V; i++) {
            availableColors[i] = 1;
        }

        // Mark the colors used by neighbors as unavailable
        for (int neighbor = 0; neighbor < graph->V; neighbor++) {
            if (graph->adjMatrix[u][neighbor] && result[neighbor] != -1) {
                availableColors[result[neighbor]] = 0;
            }
        }

        // Assign the smallest available color
        for (int i = 0; i < graph->V; i++) {
            if (availableColors[i]) {
                result[u] = i;
                break;
            }
        }
    }

    // Print the results
    printf("Vertex\tColor\n");
    for (int i = 0; i < graph->V; i++) {
        printf("%d\t%d\n", i, result[i]);
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < numEdges; i++) {
        int v, w;
        scanf("%d %d", &v, &w);
        addEdge(&graph, v, w);
    }

    // Apply greedy coloring algorithm
    greedyColoring(&graph);

    return 0;
}
