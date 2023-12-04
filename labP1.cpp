// Linear Search and Binary Search
#include <iostream>
#include <ctime>

using namespace std;

// Recursive binary search
int binarySearch(int arr[], int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, target, left, mid - 1);
        return binarySearch(arr, target, mid + 1, right);
    }
    return -1; // Element not found
}

// Linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1; // Element not found
}

int main() {
    int n; // Number of elements to search
    cout << "Enter the number of elements (n): ";
    cin >> n;

    int arr[n]; // Initialize an array

    // Generate a list of integers from 1 to n
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    int target; // Element to search for
    cout << "Enter the target element to search for: ";
    cin >> target;

    // Measure time for binary search
    clock_t start = clock();
    int binaryResult = binarySearch(arr, target, 0, n - 1);
    clock_t stop = clock();
    double binaryDuration = double(stop - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds

    // Measure time for linear search
    start = clock();
    int linearResult = linearSearch(arr, n, target);
    stop = clock();
    double linearDuration = double(stop - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds

    if (binaryResult != -1) {
        cout << "Binary Search: Element found at index " << binaryResult << endl;
        cout << "Time taken for binary search: " << binaryDuration << " microseconds" << endl;
    } else {
        cout << "Binary Search: Element not found" << endl;
    }

    if (linearResult != -1) {
        cout << "Linear Search: Element found at index " << linearResult << endl;
        cout << "Time taken for linear search: " << linearDuration << " microseconds" << endl;
    } else {
        cout << "Linear Search: Element not found" << endl;
    }

    return 0;
}


