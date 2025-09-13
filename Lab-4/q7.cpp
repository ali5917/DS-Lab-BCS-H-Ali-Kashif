#include <iostream>
using namespace std;

void shellSort (int arr [], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int current = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > current) {
                arr[j + gap] = arr[j];
                j -= gap; 
            }
            
            arr[j + gap] = current;
        }
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
    
    // performing shell sort 
    cout << "Original Array:\n";
    displayArray(arr, size);
    
    shellSort(arr, size);
    
    cout << "\nSorted Array:\n";
    displayArray(arr, size);
    
    delete [] arr;
}