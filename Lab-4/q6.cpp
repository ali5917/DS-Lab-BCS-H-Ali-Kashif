#include <iostream>
using namespace std;

void combSort (int arr [], int size, int &comparisons, int &swaps) {  
    int gap = size;
    bool noSwap = false;
    
    while (gap > 1 || !noSwap) {
        noSwap = true;
        gap /= 1.3;
        if (gap < 1) gap = 1;

        for (int i = 0; i + gap < size; i++) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swaps++;
                noSwap = false;
            }
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
    
    // performing comb sort 
    int comparisons = 0, swaps = 0;
    cout << "Original Array:\n";
    displayArray(arr, size);
    
    combSort(arr, size, comparisons, swaps);
    
    cout << "\nSorted Array:\n";
    displayArray(arr, size);
    
    cout << "\nTotal comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    delete [] arr;
}   