#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0;  // Initial index of first subarray
    int j = 0;  // Initial index of second subarray
    int k = l;  // Initial index of merged subarray

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

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
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

        // Measure execution time for merge sort
        clock_t start = clock();
        merge_sort(arr, 0, n - 1);
        clock_t end = clock();
        double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        cout << "n = " << n << ", Merge Sort Time (seconds): " << elapsedTime << endl;

        // Free the dynamically allocated memory
        delete[] arr;
    }

    return 0;
}
