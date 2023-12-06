#include <iostream>

using namespace std;

int knapsack(int values[], int weights[], int n, int capacity) {
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[capacity + 1];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    int result = dp[n][capacity];

    // Deallocate memory
    for (int i = 0; i <= n; ++i) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    const int n = 3; // Number of items
    int values[n] = {60, 100, 120};
    int weights[n] = {10, 20, 30};

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int result = knapsack(values, weights, n, capacity);

    cout << "Maximum value: " << result << endl;

    return 0;
}
