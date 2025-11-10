#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

class Queue {
    private:
        int front;
        int rear;
        int arr[MAX];

    public:
        Queue() : front(-1), rear(-1) {}
        
        bool isFull () {return (rear == MAX - 1);}
        bool isEmpty () {return (front == -1);}

        void enqueue (int x) {
            if (isFull()) {
                cout << "Queue is Full, can't enqueue!\n";
                return;
            }

            if (isEmpty()) front = 0;
            arr[++rear] = x;
            cout << "Enqueued: " << x << endl;
            return;
        } 

        int dequeue () {
            if (isEmpty()) {
                cout << "Queue is Empty, can't dequeue!";
                return -1;
            }

            int x = arr[front];
            if (front == rear) {
                front = rear = -1; 
            } else {
                front++;
            }
            cout << "Dequeued: " << x << endl;
            return x;
        }

        void display () {
            if (isEmpty()) {
                cout << "Queue is empty!\n";
                return;
            }

            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.display();
}