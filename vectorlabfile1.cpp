#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Implement recursive binary search
int binary_search(vector<int>& arr, int target, int low, int high) {
    if (low > high) {
        return -1;  // Element not found
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;  // Element found
    } else if (arr[mid] < target) {
        return binary_search(arr, target, mid + 1, high);
    } else {
        return binary_search(arr, target, low, mid - 1);
    }
}

// Implement linear search
int linear_search(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Element found
        }
    }
    return -1;  // Element not found
}

int main() {
    vector<int> n_values = {100000, 1000000, 10000000};  // Increase the values

    for (int n : n_values) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }
        int target = n / 2;  // Target value in the middle

        // Measure execution time for binary search
        clock_t binaryStart = clock();
        int binarySearchResult = binary_search(arr, target, 0, arr.size() - 1);
        clock_t binaryEnd = clock();
        double binarySearchTime = static_cast<double>(binaryEnd - binaryStart) / CLOCKS_PER_SEC;

        // Measure execution time for linear search
        clock_t linearStart = clock();
        int linearSearchResult = linear_search(arr, target);
        clock_t linearEnd = clock();
        double linearSearchTime = static_cast<double>(linearEnd - linearStart) / CLOCKS_PER_SEC;

        // Output the results
        cout << "n = " << n << ", Target = " << target << endl;
        cout << "Binary Search Time (seconds): " << binarySearchTime << endl;
        cout << "Linear Search Time (seconds): " << linearSearchTime << endl;
        cout << "----------------------------------------------" << endl;
    }

    return 0;
}
