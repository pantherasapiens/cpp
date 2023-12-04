#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to partition the array into two subarrays
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick sort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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

        // Measure execution time for quick sort
        clock_t start = clock();
        quick_sort(arr, 0, n - 1);
        clock_t end = clock();
        double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        cout << "n = " << n << ", Quick Sort Time (seconds): " << elapsedTime << endl;

        // Free the dynamically allocated memory
        delete[] arr;
    }

    return 0;
}
