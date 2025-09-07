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

class DNode {
public:
    int value;
    DNode *prev;
    DNode *next;
    DNode(int val) : value(val), next(nullptr), prev(nullptr) {}
};

// converting a singly linked list to doubly linked list 
DNode* convertToDoubly(Node* head) {
    if (!head) return nullptr;

    DNode *newHead = new DNode(head->value);
    Node *p = head->next;
    
    DNode *prev = newHead;
    while (p) {
        DNode *thisNode = new DNode(p->value);
        thisNode->prev = prev;
        prev->next = thisNode;

        prev = thisNode;
        p = p->next;        
    }
    return newHead;
}


// converting a singly linked list to circular linked list 
Node* convertToCircular(Node* head) {
    if (!head) return nullptr;

    Node *p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = head;
    return head;
}

Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* p = head;
    for (int i = 1; i < n; i++) {
        p->next = new Node(arr[i]);
        p = p->next;
    }
    return head;
}

void printList(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->value;
        if (p->next) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

void printDoubly(DNode* head) {
    DNode* p = head;
    while (p) {
        cout << p->value;
        if (p->next) cout << " <-> ";
        p = p->next;
    }
    cout << endl;
}

void printCircular(Node* head, int count) {
    if (!head) return;

    Node* p = head;
    for (int i = 0; i < count; i++) {
        cout << p->value;
        if (i < count - 1) cout << " -> ";
        p = p->next;
    }
    cout << " -> ..." << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = createList(arr, 5);

    cout << "Original Singly Linked List: ";
    printList(head);

    DNode* dhead = convertToDoubly(head);
    cout << "Converted Doubly Linked List: ";
    printDoubly(dhead);

    Node* cHead = convertToCircular(head);
    cout << "Converted Circular Linked List: ";
    printCircular(cHead, 10);

    return 0;
}