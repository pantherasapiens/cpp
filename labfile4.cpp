#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Selection sort function
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[min_index]);
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

        // Measure execution time for selection sort
        clock_t start = clock();
        selection_sort(arr, n);
        clock_t end = clock();
        double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        cout << "n = " << n << ", Selection Sort Time (seconds): " << elapsedTime << endl;

        // Free the dynamically allocated memory
        delete[] arr;
    }

    return 0;
}
