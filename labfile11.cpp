#include <iostream>

using namespace std;

const int INF = 1e9; // A large positive integer value as a substitute for INT_MAX.
const int MAX_V = 100; // Adjust the maximum number of vertices as needed.

int findMinCostVertex(int costs[], bool inMST[], int V) {
    int minCost = INF;
    int minCostVertex = -1;

    for (int v = 0; v < V; v++) {
        if (!inMST[v] && costs[v] < minCost) {
            minCost = costs[v];
            minCostVertex = v;
        }
    }

    return minCostVertex;
}

void primMST(int graph[MAX_V][MAX_V], int V) {
    int parent[MAX_V];
    int costs[MAX_V];
    bool inMST[MAX_V];

    for (int i = 0; i < V; i++) {
        costs[i] = INF;
        inMST[i] = false;
    }

    costs[0] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = findMinCostVertex(costs, inMST, V);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < costs[v]) {
                parent[v] = u;
                costs[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < V; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " Cost: " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices
    int graph[MAX_V][MAX_V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Minimum Cost Spanning Tree Edges:" << endl;
    primMST(graph, V);

    return 0;
}
