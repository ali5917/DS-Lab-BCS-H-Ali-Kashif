#include <iostream>
#include <string>

using namespace std;

int backtrack (char matrix[6][6], int x, int y, int energy) {
    // base case
    if (x == 5 && y == 5) {
        return energy;
    }
    // apply
    char thisCell = matrix[x][y];
    if (matrix[x][y] == 'H') energy -= 5;
    matrix[x][y] = 'D';

    // recurse
    int maxEnergy = -1;

    if (x > 0 && matrix[x - 1][y] != 'D') maxEnergy = max(backtrack(matrix, x - 1, y, energy), maxEnergy);
    if (x < 5 && matrix[x + 1][y] != 'D') maxEnergy = max(backtrack(matrix, x + 1, y, energy), maxEnergy);
    if (y > 0 && matrix[x][y - 1] != 'D') maxEnergy = max(backtrack(matrix, x, y - 1, energy), maxEnergy);
    if (y < 5 && matrix[x][y + 1] != 'D') maxEnergy = max(backtrack(matrix, x, y + 1, energy), maxEnergy);

    // undo
    matrix[x][y] = thisCell;

    return maxEnergy;
}

int main() {
    char matrix[6][6] = {
        {'S', 'P', 'P', 'D', 'H', 'H'},
        {'P', 'P', 'P', 'D', 'P', 'H'},
        {'P', 'H', 'P', 'P', 'P', 'D'},
        {'P', 'D', 'P', 'D', 'P', 'P'},
        {'P', 'P', 'P', 'H', 'H', 'D'},
        {'P', 'D', 'H', 'P', 'P', 'T'}
    };

    int fullEnergy = 100;
    int maxEnergyLeft = backtrack(matrix, 0, 0, fullEnergy);

    if (maxEnergyLeft == -1)
        cout << "No path to treasure found!" << endl;
    else
        cout << "Maximum remaining energy: " << maxEnergyLeft << endl;

    return 0;
}