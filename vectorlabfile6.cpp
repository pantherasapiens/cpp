#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;  // A large constant to represent infinity

// Structure to represent an edge
struct Edge {
    int destination;
    int weight;
};

// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& distances, const vector<bool>& processed) {
    int minDist = INF;
    int minIndex = -1;

    for (int i = 0; i < distances.size(); ++i) {
        if (!processed[i] && distances[i] <= minDist) {
            minDist = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to print the shortest path from the source vertex to a given vertex
void printShortestPath(const vector<int>& parent, int vertex) {
    if (parent[vertex] == -1) {
        cout << "Vertex " << vertex;
        return;
    }

    printShortestPath(parent, parent[vertex]);
    cout << " -> Vertex " << vertex;
}

// Function to run Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int source) {
    int V = graph.size();
    vector<int> distances(V, INF);   // Array to store the shortest distances from the source
    vector<bool> processed(V, false);  // Array to track processed vertices
    vector<int> parent(V, -1);       // Array to store the parent vertices for constructing the shortest path tree

    distances[source] = 0;  // Distance from the source to itself is 0

    for (int i = 0; i < V; ++i) {
        int u = minDistance(distances, processed);
        processed[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;
            if (!processed[v] && distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
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

    vector<vector<Edge>> graph(V);

    cout << "Enter the edges (source destination weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});  // For an undirected graph
    }

    int source;  // Source vertex
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
