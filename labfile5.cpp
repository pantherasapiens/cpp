#include <iostream>

using namespace std;

int knapsack_01(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Reconstruct the selected items
    int selected_items[n];
    int i = n, w = capacity;
    int items_count = 0;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items[items_count++] = i - 1;
            w -= weights[i - 1];
        }
        i--;
    }

    // Print the selected items
    cout << "Selected items: ";
    for (int j = items_count - 1; j >= 0; j--) {
        cout << selected_items[j] << " ";
    }
    cout << endl;

    return dp[n][capacity];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    int max_value = knapsack_01(values, weights, n, capacity);

    cout << "Maximum value: " << max_value << endl;

    return 0;
}
