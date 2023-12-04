#include <iostream>

using namespace std;

const int maxVertices = 100;  // Maximum number of vertices (adjust as needed)
const int INF = 1e9;         // A large constant to represent infinity

// Function to find the vertex with the minimum distance value
int minDistance(int distances[], bool processed[], int V) {
    int minDist = INF;
    int minIndex = -1;

    for (int i = 0; i < V; ++i) {
        if (!processed[i] && distances[i] <= minDist) {
            minDist = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to print the shortest path from the source vertex to a given vertex
void printShortestPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        cout << "Vertex " << vertex;
        return;
    }

    printShortestPath(parent, parent[vertex]);
    cout << " -> Vertex " << vertex;
}

// Function to run Dijkstra's algorithm
void dijkstra(int graph[maxVertices][maxVertices], int source, int V) {
    int distances[maxVertices];       // Array to store the shortest distances from the source
    bool processed[maxVertices];      // Array to track processed vertices
    int parent[maxVertices];          // Array to store the parent vertices for constructing the shortest path tree

    for (int i = 0; i < V; ++i) {
        distances[i] = INF;
        processed[i] = false;
        parent[i] = -1;
    }

    distances[source] = 0;  // Distance from the source to itself is 0

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(distances, processed, V);
        processed[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!processed[v] && graph[u][v] && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the shortest paths and their distances
    cout << "Shortest Paths from Source Vertex " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        if (i != source) {
            cout << "To Vertex " << i << ": ";
            printShortestPath(parent, i);
            cout << " (Distance: " << distances[i] << ")\n";
        }
    }
}

int main() {
    int V, E;  // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    int graph[maxVertices][maxVertices] = {0};  // Initialize the graph with 0 weight for all edges

    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;  // For an undirected graph
    }

    int source;  // Source vertex
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source, V);

    return 0;
}
