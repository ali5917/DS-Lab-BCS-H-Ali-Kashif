// Implement a calculator using a doubly linked list, 
// where each node stores either a number, operator (+ - * /), or bracket.
// Traverse the list, combine digits, respect operator precedence and solve inner brackets first
// then output the final result.

// ------ FEW ERRORS IN CODE ------

#include <iostream>
#include <string>
using namespace std;

// class declarations
class Node {
    public:
        string data;
        Node *next;
        Node *prev;

        Node (string val) : data (val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
    public:
    Node *head;
    Node *tail;

    LinkedList () : head(nullptr), tail(nullptr) {}

    void append(string val) {
        Node *t = new Node(val);
        if (!head) {
            head = tail = t;
        } else {
            tail->next = t;
            t->prev = tail;
            tail = t;
        }
    }

    int calculate () {
        Node *startBracket = head;
        Node *endBracket = tail;

        while (head != tail) {
            // find subexpression
            Node *p = head;
            while (p) {
                if (p->data == ")") {
                    endBracket = p;
                    while (p->data != "(") p = p->prev;
                    startBracket = p;
                    break;
                }
                p = p->next;
            }

            int subResult = calculateSubExp(startBracket->next, endBracket->prev);
            Node *resNode = new Node (to_string(subResult));
            Node *node1 = startBracket->prev;
            Node *node2 = endBracket->next;

            if (node1) node1->next = resNode; else head = resNode;
            if (node2) node2->prev = resNode; else tail = resNode;
            resNode->prev = node1;
            resNode->next = node2;
        }

        return stoi(head->data);
    }

    int calculateSubExp (Node *start, Node *end) {
        if (start == end) return stoi(start->data);

        while (start != end) {
            bool calcFlag = false;
            Node *p = start;
            Node *resNode = new Node (""); // initialized
            while (p != end && !calcFlag) {
                if (p->data == "divide") {
                    int result = stoi(p->prev->data) / stoi(p->next->data);
                    resNode->data = to_string(result);
                    calcFlag = true;

                    if (p->prev == start) start = resNode;
                    if (p->next == end) end = resNode;
                    
                    Node* before = p->prev->prev; 
                    Node* after = p->next->next;  

                    resNode->prev = before;
                    resNode->next = after;

                    if(before) before->next = resNode; else head = resNode;
                    if(after) after->prev = resNode; else tail = resNode;
                } else p = p->next;
            }

            p = start;
            while (p != end && !calcFlag) {
                if (p->data == "multiply") {
                    int result = stoi(p->prev->data) * stoi(p->next->data);
                    resNode->data = to_string(result);
                    calcFlag = true;

                    if (p->prev == start) start = resNode;
                    if (p->next == end) end = resNode;
                    
                    Node* before = p->prev->prev; 
                    Node* after = p->next->next;  

                    resNode->prev = before;
                    resNode->next = after;

                    if(before) before->next = resNode; else head = resNode;
                    if(after) after->prev = resNode; else tail = resNode;
                } else p = p->next;
            }
            
            p = start;
            while (p != end && !calcFlag) {
                if (p->data == "add") {
                    int result = stoi(p->prev->data) + stoi(p->next->data);
                    resNode->data = to_string(result);
                    calcFlag = true;

                    if (p->prev == start) start = resNode;
                    if (p->next == end) end = resNode;
                    
                    Node* before = p->prev->prev; 
                    Node* after = p->next->next;  

                    resNode->prev = before;
                    resNode->next = after;

                    if(before) before->next = resNode; else head = resNode;
                    if(after) after->prev = resNode; else tail = resNode;
                } else p = p->next;
            }

            p = start;
            while (p != end && !calcFlag) {
                if (p->data == "minus") {
                    int result = stoi(p->prev->data) - stoi(p->next->data);
                    resNode->data = to_string(result);
                    calcFlag = true;

                    if (p->prev == start) start = resNode;
                    if (p->next == end) end = resNode;
                    
                    Node* before = p->prev->prev;
                    Node* after = p->next->next;  

                    resNode->prev = before;
                    resNode->next = after;

                    if(before) before->next = resNode; else head = resNode;
                    if(after) after->prev = resNode; else tail = resNode;
                } else p = p->next;
            }
        }
        return stoi(start->data);
    }
};

int main() {
    LinkedList list;

    list.append("10");
    list.append("add");
    list.append("(");
    list.append("12");
    list.append("multiply");
    list.append("(");
    list.append("2");
    list.append(")");
    list.append("minus");
    list.append("2");
    list.append(")");

    int result = list.calculate();
    cout << "Result: " << result << endl;

    return 0;
}