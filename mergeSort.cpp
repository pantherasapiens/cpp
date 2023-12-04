// merge sort
#include<iostream>
using namespace std;

void mergeSortMerge(int arr[],int arr1[],int arr2[],int size1,int size2){
    int i=0,j=0,k=0;
    while(j<size1 && k<size2){
            if(arr1[j]<arr2[k]){
                arr[i]=arr1[j];
                j=j++;
            }
            else{
                arr[i]=arr2[k];
                k=k++;
            }
            i++;
    }
    while (i<size1) {
        arr[i] = arr1[j];
        i++;
        j++;
    }

    while (j<size2) {
        arr[i] = arr2[k];
        i++;
        k++;
    }
}

void mergeSortDivide(int arr[], int size){
    if(size>1) {
        int size1 = size/2;
        int size2 = size-(size/2);
        int* arr1 = new int[size1];
        int *arr2 = new int[size2];
        for(int i=0;i<size1;i++){
            arr1[i]=arr[i];
        }
        for(int i=0,j=size/2;i<size2,j<size;i++,j++){
            arr2[i]=arr[j];
        }
        // printing the arrays
        cout << "\nPrinting array1:\n";
        for(int i=0;i<size1;i++){
            cout << arr1[i] << "\t";
        }
        cout << "\nPrinting array2:\n";
        for(int i=0;i<size2;i++){
            cout << arr2[i] << "\t";
        }
        mergeSortDivide(arr1,size1);
        mergeSortDivide(arr2,size2);
        mergeSortMerge(arr,arr1,arr2,size1,size2);

        delete[] arr1;
        delete[] arr2;
    }
}

int main(){
    int size;
    int* arr;
    cout << "enter size of array: ";
    cin >> size;
    arr = new int(size);
    cout << "enter elements of array:\n";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    } 
    mergeSortDivide(arr,size);
    cout << "\nprinting final output\n";
    for(int i=0;i<size;i++){
        cout << arr[i] << "\t";
    }
    return 0;
}