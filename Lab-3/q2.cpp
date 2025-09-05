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

Node* mergeSortedLists (Node *head1, Node *head2) {
    if (!head1) return head2; 
    if (!head2) return head1;
    
    Node *head3 = nullptr, *tail3 = nullptr;
    if (head1->value < head2->value) {
        head3 = tail3 = head1;
        head1 = head1->next;
    } else {
        head3 = tail3 = head2;
        head2 = head2->next;
    }

    while (head1 && head2) {
        if (head1->value < head2->value) {
            tail3->next = head1;
            tail3 = tail3->next;
            head1 = head1->next;
        } else {
            tail3->next = head2;
            tail3 = tail3->next;
            head2 = head2->next;
        }        
    }

    if (head1) tail3->next = head1;
    if (head2) tail3->next = head2;

    return head3;
}