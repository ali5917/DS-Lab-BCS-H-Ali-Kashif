#include <iostream>
using namespace std;

// tail recursion
int sumTail(int n, int total) {
    if (n == 0) {
        return total;
    } 

    return sumTail(n - 1, total + n);
}

// non-tail recursion
int sumNonTail(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumNonTail(n - 1);
}

// Difference in implementations: 
// In the non-tail version, each call has to remember the pending addition until the very end.
// In the tail version, nothing is left to remember because the running total is carried along with each call.

int main () {
    int num = 5;
    cout << "The Sum of 1 - " << num << ": " << sumTail(num, 0);
}