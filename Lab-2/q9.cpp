#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int * [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "\nEnter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ":\n";
        for (int j = 0; j < cols; j++) {
            cout << "CoLUMN " << j << ": ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix in normal form:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix iin compressed form:\n";
    int zeros = 0, nonzeros = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                cout << "(" << i << ", " << j << ", " << matrix[i][j] << ")\n";
                nonzeros++;
            } else {
                zeros++;
            }
        }
    }

    cout << "\nRows = " << rows << ", Cols = " << cols << " | Non-zeros = " << nonzeros << ", Zeros = " << zeros << endl;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}