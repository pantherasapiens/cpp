// knapsack Problem
#include <iostream>

using namespace std;

// Structure to represent items
struct Item {
    int weight;
    int value;
};

// Function to solve the 0/1 knapsack problem using dynamic programming
int knapsack(Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    Item items[] = {
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 5;

    int max_value = knapsack(items, n, capacity);

    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
