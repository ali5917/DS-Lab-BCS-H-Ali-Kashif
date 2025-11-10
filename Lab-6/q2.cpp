#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node (int x) : data (x), next(nullptr) {}
};

class Stack {
    private:
        Node *top;
        
    public:
        Stack () : top(nullptr) {}

        bool push (int x) {
            Node *newNode = new Node (x);
            if (!newNode) {
                cout << "Heap Overflow!\n";
                return false;
            } 

            newNode->next = top;
            top = newNode;
            cout << x << " pushed!\n";
            return true;
        }

        int pop () {
            if (!top) {
                cout << "No item to pop!\n";
                return -1;
            }

            Node *temp = top;
            top = temp->next;
            int x = temp->data;
            delete temp;
            return x;
        }

        int peek () {
            if (!top) {
                cout << "No item to pop!\n";
                return -1;
            }

            return top->data;
        }

        bool isEmpty () {
            return (top == nullptr);
        }

        void display() {
            if (!top) {
                cout << "Stack is Empty!\n";
                return;
            }
            
            cout << "Stack elements: ";
            Node *p = top;
            while (p) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
};

int main() {
    Stack s;

    cout << "--- Stack Implementation using Linked List  ---\n\n";

    cout << "Pushing elements onto the stack:\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();

    cout << "\nTop element: " << s.peek() << endl;

    cout << "\nPopping two elements...\n";
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    cout << "\nStack after popping:\n";
    s.display();

    cout << "\nIs stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout << "\nPopping remaining elements...\n";
    s.pop();
    s.pop();

    cout << "\nTrying to pop from empty stack:\n";
    s.pop(); 

    cout << "\nIs stack empty now? " << (s.isEmpty() ? "Yes" : "No") << endl;
}