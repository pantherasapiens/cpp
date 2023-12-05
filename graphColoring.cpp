#include <iostream>

using namespace std;

class Graph {
    int V; // Number of vertices
    int** adjMatrix;

public:
    Graph(int vertices) : V(vertices) {
        // Allocate memory for the adjacency matrix
        adjMatrix = new int*[V];
        for (int i = 0; i < V; ++i) {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = 0; // Initialize all elements to 0
            }
        }
    }

    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1; // Assuming an undirected graph
    }

    void greedyColoring() {
        int* result = new int[V]; // Initialize all vertices as unassigned
        int* availableColors = new int[V];
        
        // Assign the first color to the first vertex
        result[0] = 0;
        availableColors[0] = 1;

        // Process the remaining vertices
        for (int u = 1; u < V; u++) {
            // Initialize the available colors for the current vertex
            for (int i = 0; i < V; i++) {
                availableColors[i] = 1;
            }

            // Mark the colors used by neighbors as unavailable
            for (int neighbor = 0; neighbor < V; neighbor++) {
                if (adjMatrix[u][neighbor] && result[neighbor] != -1) {
                    availableColors[result[neighbor]] = 0;
                }
            }

            // Assign the smallest available color
            for (int i = 0; i < V; i++) {
                if (availableColors[i]) {
                    result[u] = i;
                    break;
                }
            }
        }

        // Print the results
        cout << "Vertex\tColor\n";
        for (int i = 0; i < V; i++) {
            cout << i << "\t" << result[i] << "\n";
        }

        // Free allocated memory
        delete[] result;
        delete[] availableColors;
    }

    // Destructor to free allocated memory
    ~Graph() {
        for (int i = 0; i < V; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph graph(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (vertex1 vertex2):\n";
    for (int i = 0; i < numEdges; i++) {
        int v, w;
        cin >> v >> w;
        graph.addEdge(v, w);
    }

    // Apply greedy coloring algorithm
    graph.greedyColoring();

    return 0;
}
