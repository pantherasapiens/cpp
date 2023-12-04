// Heap Sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Heapify a subtree rooted at the given index
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heapsort function
void heapSort(int arr[], int n) {
    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Number of experiments (different values of n)
    int numExperiments = 5;

    // Initialize an array to store results
    int results[numExperiments];

    for (int exp = 1; exp <= numExperiments; exp++) {
        int n = exp * 1000; // Vary the size of the array

        // Generate random data for sorting
        int data[n];
        for (int i = 0; i < n; i++) {
            data[i] = std::rand();
        }

        // Measure the time taken for sorting
        auto start_time = std::chrono::high_resolution_clock::now();
        heapSort(data, n);
        auto end_time = std::chrono::high_resolution_clock::now();
        double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

        // Store the result (time) in the results array
        results[exp - 1] = elapsed_time;

        std::cout << "Experiment " << exp << " (n = " << n << "): " << elapsed_time << " seconds\n";
    }


    return 0;
}

