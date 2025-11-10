#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

class Stack {
    private:
        int top;
        int arr[MAX];
        
    public:
        Stack (int t = -1) : top(t) {}

        bool push (int x) {
            if (top >= MAX - 1) {
                cout << "Stack Overflow!\n";
                return false;
            }

            arr[++top] = x;
            cout << x << " pushed!\n";
            return true;
        }

        int pop () {
            if (top < 0) {
                cout << "Stack underflow!\n";
                return -1;
            }

            int x = arr[top--];
            cout << x << " popped!\n";
            return x;
        }

        int peek () {
            if (top < 0) {
                cout << "Stack underflow!\n";
                return -1;
            }

            return arr[top];
        }

        bool isEmpty () {
            return (top < 0);
        }

        void display() {
            if (top < 0) {
                cout << "Stack is Empty!\n";
                return;
            }
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main () {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.display();
}