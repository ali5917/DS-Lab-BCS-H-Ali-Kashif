//  Find all palindrome strings in an n x n character matrix using recursive traversal from any position. 
// If no palindrome exists, print a message.

// Example: 5x5 Matrix
// GROOT 
// BARRO 
// WRDBS 
// RADAR 
// WESTG 

// Output: RADAR

#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome (string str) {
    int start = 0, end = str.length() - 1;
    while (start < end) {
        if (str[start] != str[end]) return false;
        start ++;
        end --;
    }
    return true;
}

bool recur (char matrix[][5], int n, int row, int col, int rowD, int colD, string current) {
    if (row < 0 || col < 0 || row >= n || col >= n) return false;

    current.push_back(matrix[row][col]);

    if ((current.length() == n && checkPalindrome(current))) {
        cout << current << endl;
        return true;
    }

    
    return recur(matrix, n, row + rowD, col + colD, rowD, colD, current);
}

int main () {
    const int N = 5;
    char matrix [N][N] = {
        {'G','R','O','O','T'},
        {'B','A','R','R','O'},
        {'W','R','D','B','S'},
        {'R','A','D','A','R'},
        {'W','E','S','T','G'}
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (recur(matrix, N, i, j, 1, 0, "")) break;
            if (recur(matrix, N, i, j, -1, 0, "")) break;
            if (recur(matrix, N, i, j, 0, 1, "")) break;
            if (recur(matrix, N, i, j, 0, -1, "")) break;
        }
    }
}