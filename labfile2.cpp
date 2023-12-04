#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to heapify a subtree rooted at a given node
void heapify(int arr[], int n, int i) {
    int largest = i;   // Initialize the largest element as the root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2;  // Right child index

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort on an array
void heap_sort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n_values[] = {1000, 5000, 10000, 50000, 100000};  // Change the values as needed

    for (int i = 0; i < sizeof(n_values) / sizeof(n_values[0]); i++) {
        int n = n_values[i];
        int* arr = new int[n];

        // Initialize the array with random values
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }

        // Measure execution time for heap sort
        clock_t start = clock();
        heap_sort(arr, n);
        clock_t end = clock();
        double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        cout << "n = " << n << ", Heap Sort Time (seconds): " << elapsedTime << endl;

        // Free the dynamically allocated memory
        delete[] arr;
    }

    return 0;
}
