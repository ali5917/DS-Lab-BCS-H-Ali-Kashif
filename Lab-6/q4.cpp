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
        
        bool isFull () {return ((rear + 1) % MAX == front);}
        bool isEmpty () {return (front == -1);}

        void enqueue (int x) {
            if (isFull()) {
                cout << "Queue is Full, can't enqueue!\n";
                return;
            }

            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX;
            }

            arr[rear] = x;
            cout << "Enqueued: " << x << endl;
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
                front = (front + 1) % MAX;
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
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % MAX;
            }
            cout << endl;
        }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}