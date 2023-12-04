//merge sort
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// Merge two subarrays of arr[]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

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
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
        vector<int> arr(currentN);

        // Fill the vector with random values
        for (int i = 0; i < currentN; i++) {
            arr[i] = rand();
        }

        // Measure the time taken to sort the vector
        clock_t start_time = clock();
        mergeSort(arr, 0, currentN - 1);
        clock_t end_time = clock();
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;

        cout << currentN << "," << elapsed_time << endl;
    }

    return 0;
}

