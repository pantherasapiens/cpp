// Merge Sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Function to merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
        mergeSort(data, 0, n - 1);
        auto end_time = std::chrono::high_resolution_clock::now();
        double elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

        // Store the result (time) in the results array
        results[exp - 1] = elapsed_time;

        std::cout << "Experiment " << exp << " (n = " << n << "): " << elapsed_time << " seconds\n";
    }


    return 0;
}

