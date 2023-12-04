#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// Binary search function for an array of strings
int binarySearch(string arr[], int size, string target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  // String found at index 'mid'
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // String not found
}

// Linear search function for an array of strings
int linearSearch(string arr[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // String found at index 'i'
        }
    }
    return -1;  // String not found
}

int main() {
    int size;          // Size of the array of strings
    string target;    // The string to search for

    // Input 'size', 'target', and initialize 'arr' with strings

    // Measure time for binary search
    clock_t startTime = clock();
    int result = binarySearch(arr, size, target);
    clock_t endTime = clock();
    double binarySearchTime = double(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;

    // Measure time for linear search
    startTime = clock();
    result = linearSearch(arr, size, target);
    endTime = clock();
    double linearSearchTime = double(endTime - startTime) / CLOCKS_PER_SEC * 1000.0;

    // Output binarySearchTime and linearSearchTime

    return 0;
}

