#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // A large positive integer value as a substitute for INT_MAX.

int findMinCostVertex(vector<int>& costs, vector<bool>& inMST, int V) {
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

void primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<int> costs(V, INF);
    vector<bool> inMST(V, false);

    // Start from the first vertex (you can choose any starting vertex).
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

    // Print the edges of the minimum cost spanning tree.
    for (int i = 1; i < V; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " Cost: " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Minimum Cost Spanning Tree Edges:" << endl;
    primMST(graph);

    return 0;
}
