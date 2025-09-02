#include <iostream>
using namespace std;

int main() {
    int sNum;
    cout << "Enter number of students: ";
    cin >> sNum;

    int **marks = new int*[sNum];
    int *courses = new int[sNum];

    for (int i = 0; i < sNum; i++) {
        cout << "\nEnter number of courses for student " << i + 1 << ": ";
        cin >> courses[i];
        marks[i] = new int[courses[i]];
        for (int j = 0; j < courses[i]; j++) {
            cout << "Enter marks for course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\nStudent Averages:\n";
    for (int i = 0; i < sNum; i++) {
        int sum = 0;
        for (int j = 0; j < courses[i]; j++) {
            sum += marks[i][j];
        }
        float avg = (float)sum / courses[i];
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    for (int i = 0; i < sNum; i++) {
        delete [] marks[i];
    }
    delete [] marks;
    delete [] courses;
}
