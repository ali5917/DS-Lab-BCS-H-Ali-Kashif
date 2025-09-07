#include <iostream>
using namespace std;

class MNode {
public:
    int value;
    MNode* next;
    MNode* child;

    MNode(int val) : value(val), next(nullptr), child(nullptr) {}
};

MNode* flatten(MNode* head) {
    MNode* p = head;
    while (p) {
        if (p->child) {
            // recursively flatten child first
            MNode* childHead = flatten(p->child);
            MNode* next = p->next;

            // attach child
            p->next = childHead;
            p->child = nullptr;

            // reconnect
            MNode* tail = childHead;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = next;
        }
        p = p->next;
    }
    return head;
}