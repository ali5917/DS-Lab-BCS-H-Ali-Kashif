#include <iostream>
using namespace std;

int linearSearch (const int arr [], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main () {
    // taking array and target as an input
    int size, target;
    cout << "Enter the size for an Array: ";
    cin >> size;

    int *arr = new int [size];
    cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element at index " << i << ": ";
        cin >> arr[i];
    }

    cout << "Enter the target to find: ";
    cin >> target;
    
    // performing linear search 
    int pos = linearSearch(arr, size, target);
    if (pos == -1) cout << "Element " << target << " not found in the array!\n";
    else cout << "The Element is at index " << pos << endl; 
}