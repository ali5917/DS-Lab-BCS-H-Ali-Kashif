#include <iostream>
using namespace std;

void selectionSort (int arr [], int size) {
    int index = 0, minIndex;
    while (index < size - 1) {
        minIndex = index;
        for (int i = index + 1; i < size; i++) {
            if (arr[i] < arr[minIndex]) minIndex = i;
        }

        swap(arr[index], arr[minIndex]);
        index++;
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
    
    // performing selection sort 
    cout << "Original Array:\n";
    displayArray(arr, size);
    
    selectionSort(arr, size);
    
    cout << "\nSorted Array:\n";
    displayArray(arr, size);
    delete [] arr;
}