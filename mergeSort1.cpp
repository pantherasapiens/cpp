#include <iostream>
using namespace std;

void mergeSortMerge(int arr[], int arr1[], int arr2[], int size1, int size2) {
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSortDivide(int arr[], int size) {
    if (size > 1) {
        int size1 = size / 2;
        int size2 = size - size1;
        int* arr1 = new int[size1];
        int* arr2 = new int[size2];
        
        for (int i = 0; i < size1; i++) {
            arr1[i] = arr[i];
        }
        for (int i = 0, j = size1; i < size2; i++, j++) {
            arr2[i] = arr[j];
        }
        
        mergeSortDivide(arr1, size1);
        mergeSortDivide(arr2, size2);
        mergeSortMerge(arr, arr1, arr2, size1, size2);
        
        delete[] arr1;
        delete[] arr2;
    }
}

int main() {
    int size;
    int* arr;
    cout << "Enter size of array: ";
    cin >> size;
    arr = new int[size];
    cout << "Enter elements of array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    mergeSortDivide(arr, size);
    
    cout << "\nPrinting final output:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    
    delete[] arr;
    return 0;
}
