#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Binary search function
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // Element found at index 'mid'
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Element not found
}

// Linear search function
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Element found at index 'i'
        }
    }
    return -1;  // Element not found
}

int main() {
    int size;     // Size of the array
    int target;   // The element to search for

    // Input 'size', 'target', and initialize 'arr' with elements

    // Measure time for binary search
    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, size, target);
    auto stop = high_resolution_clock::now();
    auto binarySearchTime = duration_cast<microseconds>(stop - start).count();

    // Measure time for linear search
    start = high_resolution_clock::now();
    result = linearSearch(arr, size, target);
    stop = high_resolution_clock::now();
    auto linearSearchTime = duration_cast<microseconds>(stop - start).count();

    // Output binarySearchTime and linearSearchTime

    return 0;
}

