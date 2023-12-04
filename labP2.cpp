// Selection Sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
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
        selectionSort(data, n);
        auto end_time = std::chrono::high_resolution_clock::now();
        double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

        // Store the result (time) in the results array
        results[exp - 1] = elapsed_time;

        std::cout << "Experiment " << exp << " (n = " << n << "): " << elapsed_time << " seconds\n";
    }


    return 0;
}

