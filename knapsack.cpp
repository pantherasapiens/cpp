#include <iostream>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    // Create a 2D array to store the solutions to subproblems
    int dp[n + 1][capacity + 1];

    // Initialize the dp array for the base case
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The solution to the 0/1 Knapsack problem is stored in dp[n][capacity]
    return dp[n][capacity];
}

int main() {
    // Example usage:
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int n = sizeof(weights) / sizeof(int);
    int capacity = 5;

    int result = knapsack(weights, values, n, capacity);

    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}
