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

bool isPalindrome (Node *head) {
    if (!head || !head->next) return true;

    // finding the middle node
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reversing the second half of the list
    Node *curr = slow, *prev = nullptr, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // comparing both halves of the list
    Node *p = head, *q = prev;
    while (p && q) {
        if (p->value != q->value) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}