#include <iostream>
#include <string>
using namespace std;

int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;

    string* cNames = new string [categories];
    int** books = new int * [categories];
    int* bookCounts = new int [categories];

    for (int i = 0; i < categories; i++) {
        cout << "\nEnter name of category " << i + 1 << ": ";
        cin >> cNames[i];

        cout << "Enter number of books in " << cNames[i] << ": ";
        cin >> bookCounts[i];

        books[i] = new int[bookCounts[i]];
        cout << "Enter book IDs for " << cNames[i] << ":\n";
        for (int j = 0; j < bookCounts[i]; j++) {
            cout << "  Book " << j + 1 << ": ";
            cin >> books[i][j];
        }
    }

    int searchID;
    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < bookCounts[i]; j++) {
            if (books[i][j] == searchID) {
                cout << "Book found in category: " << cNames[i] << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "Book not found!" << endl;
    }

    for (int i = 0; i < categories; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] bookCounts;
    delete[] cNames;
}