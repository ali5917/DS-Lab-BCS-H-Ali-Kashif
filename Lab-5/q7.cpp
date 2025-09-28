#include <iostream>
#include <vector>
using namespace std;

// helper function - printing 1 solution
void printSol(vector<vector<int>> &board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// helper function - checking if queen can be placed
bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    for (int i = 0; i < row; i++) if (board[i][col]) return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row-1, j = col+1; i >= 0 && j < N; i--, j++) if (board[i][j]) return false;

    return true;
}

// recursion
void solveNQueensRecur(vector<vector<int>> &board, int row, int N) {
    if (row == N) {
        printSol(board, N);
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;             
            solveNQueensRecur(board, row+1, N); 
            board[row][col] = 0;             
        }
    }
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueensRecur(board, 0, N);
}

int main() {
    int N;
    cout << "N:";
    cin >> N;

    cout << "- Solutions -" << endl;
    solveNQueens(N);
}