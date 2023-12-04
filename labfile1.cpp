#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Implement recursive binary search
int binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;  // Element found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Element not found
}

// Implement linear search
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Element found
        }
    }
    return -1;  // Element not found
}

int main() {
    int n_values[] = {100000, 1000000, 10000000};  // Increase the values

    for (int i = 0; i < sizeof(n_values) / sizeof(n_values[0]); i++) {
        int n = n_values[i];
        int* arr = new int[n];
        for (int j = 1; j <= n; j++) {
            arr[j - 1] = j;
        }
        int target = n / 2;  // Target value in the middle

        // Measure execution time for binary search
        clock_t binaryStart = clock();
        int binarySearchResult = binary_search(arr, n, target);
        clock_t binaryEnd = clock();
        double binarySearchTime = static_cast<double>(binaryEnd - binaryStart) / CLOCKS_PER_SEC;

        // Measure execution time for linear search
        clock_t linearStart = clock();
        int linearSearchResult = linear_search(arr, n, target);
        clock_t linearEnd = clock();
        double linearSearchTime = static_cast<double>(linearEnd - linearStart) / CLOCKS_PER_SEC;

        // Output the results
        cout << "n = " << n << ", Target = " << target << endl;
        cout << "Binary Search Time (seconds): " << binarySearchTime << endl;
        cout << "Linear Search Time (seconds): " << linearSearchTime << endl;
        cout << "----------------------------------------------" << endl;

        // Free the dynamically allocated memory
        delete[] arr;
    }

    return 0;
}
