#include <iostream>
using namespace std;

void insertionSort (int arr [], int size) {
    int index = 1;
    for (int i = index; i < size; i++) {
        int current = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        } 
        arr[j + 1] = current;
    }
}

void displayArray (const int arr [], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    // taking array as an input
    int size;
    cout << "Enter the size for an Array: ";
    cin >> size;

    int *arr = new int [size];
    cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element at index " << i << ": ";
        cin >> arr[i];
    }
    
    // performing insertion sort 
    cout << "Original Array:\n";
    displayArray(arr, size);
    
    insertionSort(arr, size);
    
    cout << "\nSorted Array:\n";
    displayArray(arr, size);
    
    delete [] arr;
}