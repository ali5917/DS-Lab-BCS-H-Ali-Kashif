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

Node* mergeSortedLists (Node *head, int k {
    
}