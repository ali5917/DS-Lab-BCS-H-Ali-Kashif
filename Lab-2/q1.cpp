#include <iostream>
using namespace std;

int main () {
    int *arr, size;
    cout << "Enter the size of an array: ";
    cin >> size;
    arr = new int [size];

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    cout << "Array initialized.\n";
    
    while (true) {
        int pos,val;
        cout << "\nEnter position to update (-1 to stop): ";
        cin >> pos;

        if (pos == -1) break;

        if (pos < 0 || pos >= size) {
            cout << "Invalid position.\n";
            continue;
        }

        cout << "Enter value to update at position " << pos << ": ";
        cin >> val;
        arr[pos] = val;
    }
    
    cout << "\nPrinting Array...\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";    
    }
    cout << "\n";

    delete [] arr;
}