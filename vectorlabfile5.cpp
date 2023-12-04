#include <iostream>
#include <vector>

using namespace std;

int knapsack_01(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    // Reconstruct the selected items
    vector<int> selected_items;
    int i = n, w = capacity;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items.push_back(i - 1);
            w -= weights[i - 1];
        }
        i--;
    }

    // Return the maximum value and the selected items
    cout << "Selected items: ";
    for (int item : selected_items) {
        cout << item << " ";
    }
    cout << endl;

    return dp[n][capacity];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    int max_value = knapsack_01(values, weights, capacity);

    cout << "Maximum value: " << max_value << endl;

    return 0;
}
