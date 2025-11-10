#include <iostream>
#include <string>
using namespace std;

const int N = 5;

// 8 possible directions
int dir[8][2] = {
    {-1, 0}, {1, 0},  // up, down
    {0, -1}, {0, 1},  // left, right
    {-1, -1}, {-1, 1}, // top-left, top-right
    {1, -1}, {1, 1}    // bottom-left, bottom-right
};

// check if a cell (x,y) is inside grid bounds
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// recursive backtracking search
int backtrack(char grid[N][N], string word, int x, int y, int index, bool visited[N][N]) {
    // boundary and mismatch checks first
    if (!isValid(x, y) || visited[x][y] || grid[x][y] != word[index]) return 0;

    // if we reached the last character successfully
    if (index == word.size() - 1) return 1;

    visited[x][y] = true;
    int count = 0;

    // explore all 8 directions
    for (int d = 0; d < 8; d++) {
        int newX = x + dir[d][0];
        int newY = y + dir[d][1];
        count += backtrack(grid, word, newX, newY, index + 1, visited);
    }

    visited[x][y] = false; // backtrack
    return count;
}

// counts how many times a word appears anywhere in the grid
int countOccurrences(char grid[N][N], string word) {
    int total = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == word[0]) {
                bool visited[N][N] = {false};
                total += backtrack(grid, word, i, j, 0, visited);
            }
        }
    }
    return total;
}

int main() {
    char grid[N][N] = {
        {'G', 'R', 'O', 'O', 'T'},
        {'B', 'A', 'R', 'R', 'O'},
        {'W', 'R', 'D', 'B', 'S'},
        {'R', 'A', 'D', 'A', 'R'},
        {'W', 'E', 'S', 'T', 'G'}
    };

    string words[] = {"AD", "RADAR"};
    int numWords = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < numWords; i++) {
        int found = countOccurrences(grid, words[i]);
        if (found > 0)
            cout << words[i] << " found " << found << endl;
        else
            cout << words[i] << " not found" << endl;
    }

    return 0;
}