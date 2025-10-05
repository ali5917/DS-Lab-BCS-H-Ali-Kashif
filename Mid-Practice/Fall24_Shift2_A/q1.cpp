#include <iostream>
#include <string>

using namespace std;

void replaceIndex (int arr[], int n) {
    int *newArr = new int [n];
    for (int i = 0; i < n; i++) newArr[i] = arr[i];
    
    for (int i = n - 1; i >= 0; i--) {
        bool noSwap = true;
        for (int j = 0; j < i; j++) {
            if (newArr[j] > newArr[j + 1]) {
                swap(newArr[j], newArr[j + 1]);
                noSwap = false;
            }
        }
        if (noSwap) break;
    }
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        int currentNum = newArr[i];
        if (i > 0 && currentNum == newArr[i - 1]) index--;
        for (int j = 0; j < n; j++) {
            if (arr[j] == currentNum) arr[j] = index;
        }
        index++;
    }

    delete [] newArr;
}

int main () {
    int arr[6] = {12, 5, 8, 5, 15, 8};
    replaceIndex(arr, 6);

    for (int i = 0; i < 6; i++) cout << arr[i] << " ";
}