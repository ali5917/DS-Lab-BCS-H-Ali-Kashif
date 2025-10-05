//  Sort customers by month, then day, and if equal, by name length (descending).
//  Assign hanger numbers starting from 1 in sorted order.
//  Use binary search on names to find a customer’s hanger number, returning -1 if not found.

#include <iostream>
#include <string>
using namespace std;

class Order {
    public:
        int day;
        int month;
        string name;
        int hangerNumber;
};

void sortOrders (Order *orders, int numOrders) {
    // insertion sort
    for (int i = 1; i < numOrders; i++) {
        Order current = orders[i];
        int j = i - 1;
        while (j >= 0 && (
            orders[j].month > current.month ||
            (orders[j].month == current.month && orders[j].day > current.day) ||
            (orders[j].month == current.month && orders[j].day == current.day &&
            orders[j].name.length() < current.name.length())
        )) {
            orders[j + 1] = orders[j];
            j--;
        }
        orders[j + 1] = current;
    }

    // assigning hanger numbers
    for (int i = 0; i < numOrders; i++) {
        orders[i].hangerNumber = i + 1;
    }
}

// sort alphabetically by name for binary search
void sortByName(Order arr[], int n) {
    for (int i = 1; i < n; i++) {
        Order current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].name > current.name) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

// binary search by name
int binarySearchName(Order arr[], int n, string name) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].name == name)
            return arr[mid].hangerNumber;
        else if (arr[mid].name < name)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n = 5;
    Order orders[5] = {
        {9, 9, "Mubeen"},
        {1, 9, "Ali"},
        {15, 9, "Shaheer"},
        {8, 9, "Sadiq"},
        {20, 9, "Romaan"}
    };

    // sort by date and assign hanger numbers
    sortOrders(orders, n);

    // make a copy for name-based sorting
    Order nameSorted[5];
    for (int i = 0; i < n; i++)
        nameSorted[i] = orders[i];
    sortByName(nameSorted, n);

    // binary search for hanger number by name
    string target = "Sadiq";
    int result = binarySearchName(nameSorted, n, target);
    if (result != -1)
        cout << target << " has hanger number " << result;
    else
        cout << "Customer not found";
}