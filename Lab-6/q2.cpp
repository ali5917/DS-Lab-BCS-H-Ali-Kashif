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
    Stack history;
    cout << "Pushing pages to history:\n";
    history.push(1);
    history.push(2);
    history.push(3);

    cout << "Current page: " << history.peek() << endl; // 3
    cout << "Going back to page " << history.pop() << endl;
    cout << "Now on page " << history.peek() << endl;   // 2
}