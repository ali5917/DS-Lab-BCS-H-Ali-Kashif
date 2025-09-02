#include <iostream>
using namespace std;

int main() {
    int d;
    cout << "Enter number of departments: ";
    cin >> d;

    int** salaries = new int * [d];
    int* emps = new int [d];

    for (int i = 0; i < d; i++) {
        cout << "\nNumber of employees in department " << i + 1 << ": ";
        cin >> emps[i];

        salaries[i] = new int[emps[i]];
        for (int j = 0; j < emps[i]; j++) {
            cout << "Enter salary of employee " << j + 1 << " in department " << i + 1 << ": ";
            cin >> salaries[i][j];
        }
    }

    for (int i = 0; i < d; i++) {
        int highest = salaries[i][0];
        for (int j = 1; j < emps[i]; j++) {
            if (salaries[i][j] > highest) {
                highest = salaries[i][j];
            }
        }
        cout << "\nHighest salary in Department " << i + 1 << ": " << highest;
    }

    int bestDept = 0;
    float maxAvg = 0.0;
    for (int i = 0; i < d; i++) {
        float sum = 0;
        for (int j = 0; j < emps[i]; j++) {
            sum += salaries[i][j];
        }
        float avg = sum / emps[i];
        if (avg > maxAvg) {
            maxAvg = avg;
            bestDept = i;
        }
    }

    cout << "\n\nDepartment " << bestDept + 1 << " has the maximum average salary: " << maxAvg << endl;

    for (int i = 0; i < d; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] emps;
}