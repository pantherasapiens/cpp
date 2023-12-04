// Minimum cost spanning tree of a given undirected graph using Kruskal's algorithm.
#include <iostream>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Comparator function to sort edges by weight in ascending order
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Custom sorting function
void customSort(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                swap(edges[j], edges[j + 1]);
            }
        }
    }
}

class Graph {
private:
    int V;  // Number of vertices
    int E;  // Number of edges
    Edge *edges;  // Stores the edges of the graph

public:
    Graph(int vertices, int edgesCount) : V(vertices), E(edgesCount) {
        edges = new Edge[E];
    }

    // Function to add an edge to the graph
    void addEdge(int index, int source, int destination, int weight) {
        edges[index].source = source;
        edges[index].destination = destination;
        edges[index].weight = weight;
    }

    // Function to find the parent of a subset (using union-find)
    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    // Function to perform union of two subsets (using union-find)
    void unionSets(Subset subsets[], int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank) {
            subsets[xroot].parent = yroot;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            subsets[yroot].parent = xroot;
        } else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    // Function to find the minimum spanning tree using Kruskal's algorithm
    void kruskal() {
        Edge result[V];
        int e = 0;  // Index of the sorted edge

        customSort(edges, E);  // Sort the edges by weight using custom sort

        Subset *subsets = new Subset[V];
        for (int v = 0; v < V; v++) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        int i = 0;  // Index of the selected edge
        while (e < V - 1 && i < E) {
            Edge nextEdge = edges[i++];

            int x = find(subsets, nextEdge.source);
            int y = find(subsets, nextEdge.destination);

            if (x != y) {
                result[e++] = nextEdge;
                unionSets(subsets, x, y);
            }
        }

        cout << "Minimum Spanning Tree:" << endl;
        for (int j = 0; j < e; j++) {
            cout << result[j].source << " - " << result[j].destination << " (" << result[j].weight << ")\n";
        }

        delete[] subsets;
    }
};

int main() {
    int vertices = 4;  // Number of vertices
    int edgesCount = 5;  // Number of edges

    Graph graph(vertices, edgesCount);

    // Add edges to the graph (index, source, destination, weight)
    graph.addEdge(0, 0, 1, 10);
    graph.addEdge(1, 0, 2, 6);
    graph.addEdge(2, 0, 3, 5);
    graph.addEdge(3, 1, 3, 15);
    graph.addEdge(4, 2, 3, 4);

    graph.kruskal();  // Find the minimum spanning tree

    return 0;
}
