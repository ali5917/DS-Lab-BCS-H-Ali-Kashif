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

Node* reverseKGroup (Node *head, int k) {
    Node *newHead = nullptr; // new start of the linked list
    Node *prevTail = nullptr;
    
    Node *p = head;
    while (p) {
        // reversing k nodes
        Node *prev = nullptr, *curr = p, *next = nullptr;
        Node *startK = curr;
        for (int i = 0; i < k && curr; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (!newHead) {
            newHead = prev;
        }
        
        // connecting prev reversed group to new reversed group
        if (prevTail) prevTail->next = prev;
        prevTail = startK;
        
        // moving to next group
        startK->next = curr;
        p = curr;
    }
    return newHead;
}