#include <iostream>
using namespace std;

// to be used later in main
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// helper function - checking if num can be placed
bool isValid(int grid[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) return false;
    }
    
    for (int x = 0; x < 9; x++) {
        if (grid[x][col] == num) return false;
    }

    int sRow = row - row % 3;
    int sCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + sRow][j + sCol] == num) return false;
        }
    }
    return true;
}

// helper function - find empty cell (0)
bool findEmptyCell(int grid[9][9], int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) return true;
        }
    }
    return false; 
}

// recursion 
bool solveSudoku(int grid[9][9]) {
    int row, col;
    if (!findEmptyCell(grid, row, col)) return true; 
    
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num; 
            if (solveSudoku(grid)) return true;       
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (solveSudoku(grid)) {
        cout << "- Solved Sudoku - \n";
        printGrid(grid);
    } else {
        cout << "No solution exists!\n";
    }
}