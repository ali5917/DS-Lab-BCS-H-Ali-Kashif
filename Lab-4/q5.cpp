#include <iostream>
using namespace std;

int interpolationSearch (const int arr [], int size, int target) {
    int low = 0, high = size - 1, pos;

    while (low <= high) {

        // avoid division by zero
        if (arr[high] == arr[low]) {
            if (arr[low] == target) return low;
            else break;
        }

        pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (pos < low || pos > high) break;
        
        if (arr[pos] == target) return pos;
        if (target < arr[pos]) high = pos - 1;
        else low = pos + 1;
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
    
    // performing interpolation search 
    int pos = interpolationSearch(arr, size, target);
    if (pos == -1) cout << "Element " << target << " not found in the array!\n";
    else cout << "The Element is at index " << pos << endl; 

    delete [] arr;
}