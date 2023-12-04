//selection sort
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

// Selection sort function
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
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
        selectionSort(arr);
        clock_t end_time = clock();
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;

        cout << currentN << "," << elapsed_time << endl;
    }

    return 0;
}

