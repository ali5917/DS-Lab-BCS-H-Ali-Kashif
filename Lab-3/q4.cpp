#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *next;

        Node () {
            value = 0;
            next = nullptr;
        }

        Node (int val) : value (val), next(nullptr) {}
};

int josephusProblem (int n, int k) {
    // creating circular linked list
    Node *head = new Node(1);
    Node *p = head;
    for (int i = 2; i <= n; i++) {
        p->next = new Node (i);
        p = p->next;
    }
    p->next = head;

    // traversing and deleting
    p = head;
    Node *prev = nullptr;
    while(p->next != p) {
        for (int i = 1; i < k; i++) {
            prev = p;
            p = p->next;
        }
        Node *thisNode = p;
        prev->next = p->next;
        p = p->next;
        delete thisNode;
    }
    int winner = p->value;
    delete p;
    return winner;
}