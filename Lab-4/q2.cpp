#include <iostream>
using namespace std;

void bubbleSort (int arr [], int size) {
    for (int i = size - 1; i >= 0; i--) {
        bool noSwap = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                noSwap = false;
            }
        }
        if (noSwap) return;
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
    
    // performing bubble sort 
    cout << "Original Array:\n";
    displayArray(arr, size);
    bubbleSort(arr, size);
    
    cout << "\nSorted Array:\n";
    displayArray(arr, size);
}