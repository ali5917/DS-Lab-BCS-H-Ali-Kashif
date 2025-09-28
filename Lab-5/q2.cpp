#include <iostream>
using namespace std;

// direct recursion
void printNumbers (int n) {
    if (n > 0) {
        cout << n << " ";
        printNumbers(n - 1); 
    }
}

// indirect recursion
void functionB(int n); 
void functionA(int n) {
    if (n > 0) {                
        cout << "A: " << n << " "; 
        functionB(n - 1);                 
    }
}

void functionB(int n) {
    if (n > 0) {                          
        cout << "B: " << n << " ";        
        functionA(n - 1);                 
    }
}

int main () {
    int num = 5;
    // printNumbers(num);
    functionA(num);
}