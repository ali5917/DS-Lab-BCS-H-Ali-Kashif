#include <iostream>
using namespace std;

int main () {
    int **arr, rows,cols;
    cout << "Enter the number of benches (rows): ";
    cin >> rows;
    cout << "Enter the number of seats per bench (columns): ";
    cin >> cols;
    arr = new int * [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int [cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }
    cout << "Seating initialized.\n";
    
    while (true) {
        int row,col,val;
        cout << "\nEnter bench (row) number to update (-1 to stop): ";
        cin >> row;

        if (row == -1) break;

        if (row < 0 || row >= rows) {
            cout << "Invalid position.\n";
            continue;
        }

        cout << "\nEnter seat (col) number to update: ";
        cin >> col;
        if (col < 0 || col >= cols) {
            cout << "Invalid position.\n";
            continue;
        }
        if (arr[row][col] == 1) {
            cout << "Seat Occupied! Try different seat.";
            continue;
        } else {
            arr[row][col] = 1;
        }
    }
    
    cout << "\nPrinting Final Seating Chart...\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";    
        }
        cout << endl;
    }
    cout << "\n";

    for (int i = 0; i < rows; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}