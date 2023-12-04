// quick sort
#include<iostream>
using namespace std;
void quickSortFunction(){
    
}

void quickSortPartition(int arr[],int size){
    int size1 = size/2;
    int size2 = size-(size/2);
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    for(int i=0;i<size;i++){
    }
    quickSortPartition(arr1,size1);
    quickSortPartition(arr2,size2);
}
void quickSortPartition(){
    
}
int main(){
    int size;
    int* arr;

    cout << "Enter size of the array: ";
    cin >> size;
    cout << "Enter elements of the array:\n";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    quickSortPartition(arr,size);
    return 0;
}