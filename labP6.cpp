// Dijkstra's algorithm
#include <iostream>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
const int num_vertices = 4;

// Define a structure to represent a graph edge
struct Edge {
    int target;
    int weight;
};

// Function to perform Dijkstra's algorithm
void dijkstra(Edge graph[num_vertices][num_vertices], int source, int distance[num_vertices], int parent[num_vertices]) {
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < num_vertices; ++v) {
            int w = graph[u][v].weight;

            if (w > 0 && distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
}

// Function to print the shortest path from the source to a target vertex
void printShortestPath(int parent[num_vertices], int target) {
    if (parent[target] == -1) {
        cout << "No path to " << target << " exists." << endl;
        return;
    }

    int path[num_vertices]; // Assuming a maximum of num_vertices vertices in the path
    int path_length = 0;
    int current = target;

    while (current != -1) {
        path[path_length++] = current;
        current = parent[current];
    }

    cout << "Shortest path to " << target << ": ";
    for (int i = path_length - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int source = 0;

    Edge graph[num_vertices][num_vertices] = {
        { {0, 0}, {1, 1}, {2, 4}, {3, 0} },
        { {0, 1}, {1, 0}, {2, 2}, {3, 5} },
        { {0, 4}, {1, 2}, {2, 0}, {3, 1} },
        { {0, 0}, {1, 5}, {2, 1}, {3, 0} }
    };

    int distance[num_vertices];
    int parent[num_vertices];
    for (int i = 0; i < num_vertices; ++i) {
        distance[i] = INF;
        parent[i] = -1;
    }

    dijkstra(graph, source, distance, parent);

    // Print the shortest paths from the source vertex to all other vertices
    for (int i = 0; i < num_vertices; ++i) {
        if (i != source) {
            printShortestPath(parent, i);
            cout << "Shortest distance to " << i << ": " << distance[i] << endl;
        }
    }

    return 0;
}
