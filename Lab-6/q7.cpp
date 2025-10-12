#include <iostream>
using namespace std;

#define MAX 100

class Process {
public:
    int id;
    int priority;
    Process(int i = 0, int p = 0) : id(i), priority(p) {}
};

class Stack {
private:
    int top;
    Process arr[MAX];

public:
    Stack() : top(-1) {}
    bool isEmpty() {return top < 0;}
    bool isFull() {return top >= MAX - 1;}

    void push (Process p) {
        if (isFull()) return;
        arr[++top] = p;
    }

    Process pop () {
        if (isEmpty()) return Process(-1, -1);
        return arr[top--];
    }
};

class Queue {
private:
    int front, rear;
    Process arr[MAX];

public:
    Queue() : front(-1), rear(-1) {}
    bool isEmpty() {return front == -1;}
    bool isFull() {return rear == MAX - 1;}

    void enqueue(Process p) {
        if (isFull()) return;
        if (isEmpty()) front = 0;
        arr[++rear] = p;
    }

    Process dequeue() {
        if (isEmpty()) return Process(-1, -1);
        Process x = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }

    int size() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }

    Process getProcess(int i) {return arr[front + i];}
    
    void display() {
        if (isEmpty()) {
              cout << "Queue is empty!\n";
              return;
        }
        cout << "| ";
        for (int i = front; i <= rear; i++) {
            cout << "ID " << arr[i].id << " - Priority " << arr[i].priority << " | ";
        }
        cout << endl;
    }
};

int findHighestPriority(Queue &q) {
    int high = -1;
    for (int i = 0; i < q.size(); i++) {
        Process p = q.getProcess(i);
        high = max(high, p.priority);
    }
    return high;
}

int main() {
    Queue readyQueue;
    Stack executionStack;

    readyQueue.enqueue(Process(0, 2));
    readyQueue.enqueue(Process(1, 5));
    readyQueue.enqueue(Process(2, 3));
    readyQueue.enqueue(Process(3, 5));
    readyQueue.enqueue(Process(4, 1));

    cout << "Initial Queue State:\n";
    readyQueue.display();
    cout << endl;

    while (!readyQueue.isEmpty()) {
        int highest = findHighestPriority(readyQueue);
        int size = readyQueue.size();

        for (int i = 0; i < size; i++) {
            Process p = readyQueue.dequeue();
            if (p.priority == highest) executionStack.push(p);
            else readyQueue.enqueue(p);
        }

        while (!executionStack.isEmpty()) {
            Process p = executionStack.pop();
            cout << "Executing Process ID " << p.id << " (Priority " << p.priority << ")\n";
        }
    }
}