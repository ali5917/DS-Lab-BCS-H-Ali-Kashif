#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of months to track: ";
    cin >> n;

    float *expenses = new float[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter expense for month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    char choice;
    cout << "\nDAdd more months? (Y/N): ";
    cin >> choice;

    if (choice == 'Y') {
        int e;
        cout << "Number of extra months: ";
        cin >> e;

        float *newArr = new float[n + e];
        for (int i = 0; i < n; i++) {
            newArr[i] = expenses[i];
        }
        delete [] expenses;
        expenses = newArr;

        for (int i = n; i < n + e; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> expenses[i];
        }
        n += e;
    }

    float total = 0;
    for (int i = 0; i < n; i++) {
        total += expenses[i];
    }

    cout << "\nTotal expenses: " << total << endl;
    cout << "Average expenses: " << total / n << endl;

    delete [] expenses;
}
