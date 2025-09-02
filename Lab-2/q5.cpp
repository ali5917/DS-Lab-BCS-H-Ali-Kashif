#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Number of rows: ";
    cin >> rows;
    cout << "Number of columns: ";
    cin >> cols;

    int **matrixA = new int * [rows];
    int **matrixB = new int * [rows];
    int **matrixC = new int * [rows];

    for (int i = 0; i < rows; i++) {
        matrixA[i] = new int [cols];
        matrixB[i] = new int [cols];
        matrixC[i] = new int [cols];
    }

    cout << "\nEnter elements of Matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "\nEnter elements of Matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrixB[i][j];
        }
    }

    cout << "\nAddition (A + B -> C):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSubtraction (A - B -> C):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete [] matrixA[i]; 
        delete [] matrixB[i];
        delete [] matrixC[i];
    }
    delete [] matrixA;
    delete [] matrixB;
    delete [] matrixC;
}