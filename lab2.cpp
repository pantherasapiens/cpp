//heap sort
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Function to perform the heapify operation in heap sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the maximum value of n (number of elements): ";
    cin >> n;

    // Initialize random seed
    srand(time(0));

    cout << "n,Time (ms)" << endl;

    for (int currentN = 1; currentN <= n; currentN++) {
        int arr[currentN];

        // Fill the array with random values
        for (int i = 0; i < currentN; i++) {
            arr[i] = rand();
        }

        // Measure the time taken to sort the array
        clock_t start_time = clock();
        heapSort(arr, currentN);
        clock_t end_time = clock();
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;

        cout << currentN << "," << elapsed_time << endl;
    }

    return 0;
}

