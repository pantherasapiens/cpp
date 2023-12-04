// Quick Sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        quickSort(data, 0, n - 1);
        auto end_time = std::chrono::high_resolution_clock::now();
        double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

        // Store the result (time) in the results array
        results[exp - 1] = elapsed_time;

        std::cout << "Experiment " << exp << " (n = " << n << "): " << elapsed_time << " seconds\n";
    }


    return 0;
}

