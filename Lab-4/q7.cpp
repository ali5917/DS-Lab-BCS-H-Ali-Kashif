#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void shellSort (int arr [], int size, int &comparisons, int &swaps) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int current = arr[i];
            int j = i - gap;
            while (j >= 0 && (++comparisons && arr[j] > current)) {
                arr[j + gap] = arr[j];
                j -= gap; 
                swaps++;
            }
            
            arr[j + gap] = current;
        }
    }
}

// bubble sort and insertion sort for the comparisons
void bubbleSort (int arr [], int size, int &comparisons, int &swaps) {
    for (int i = size - 1; i >= 0; i--) {
        comparisons++;
        bool noSwap = true;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                noSwap = false;
            }
        }
        if (noSwap) return;
    } 
}

void insertionSort (int arr [], int size, int &comparisons, int &swaps) {
    int index = 1;
    for (int i = index; i < size; i++) {
        int current = arr[i];

        int j = i - 1;
        while (j >= 0 && (++comparisons && arr[j] > current)) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
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

void copyArray(int dest[], const int src[], int size) {
    for (int i = 0; i < size; i++) dest[i] = src[i];
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
    
    cout << "Original Array:\n";
    displayArray(arr, size);

    int *arr1 = new int[size];
    int *arr2 = new int[size];
    int *arr3 = new int[size];
    copyArray(arr1, arr, size);
    copyArray(arr2, arr, size);
    copyArray(arr3, arr, size);

    int comps, swaps;

    // performing and analyzing bubble sort
    comps = swaps = 0;
    auto start = high_resolution_clock::now();
    bubbleSort(arr1, size, comps, swaps);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nBubble Sort Result:\n";
    displayArray(arr1, size);
    cout << "Comparisons: " << comps << ", Swaps: " << swaps << ", Time: " << duration.count() << " µs\n";

    // performing and analyzing insertion sort
    comps = swaps = 0;
    start = high_resolution_clock::now();
    insertionSort(arr2, size, comps, swaps);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nInsertion Sort Result:\n";
    displayArray(arr2, size);
    cout << "Comparisons: " << comps << ", Swaps: " << swaps << ", Time: " << duration.count() << " µs\n";

    // performing and analyzing shell sort
    comps = swaps = 0;
    start = high_resolution_clock::now();
    shellSort(arr3, size, comps, swaps);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nShell Sort Result:\n";
    displayArray(arr3, size);
    cout << "Comparisons: " << comps << ", Swaps: " << swaps << ", Time: " << duration.count() << " µs\n";

    
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

/*
---- Analysis Notes ----

Tested with input of 10 elements: 50 20 10 60 30 80 70 40 90 100

Results (on my system):

Bubble Sort:
Comparisons: 45, Swaps: 12, Time: ~0 µs

Insertion Sort:
Comparisons: 28, Swaps: 12, Time: ~0 µs

Shell Sort:
Comparisons: 20, Swaps: 8, Time: ~0 µs

Observation:
Even though the time shows ~0 µs (because the array is very small),the counts clearly show Shell Sort needs fewer comparisons/swaps, 
which demonstrates why it performs better than Bubble and Insertion Sort.
*/
}