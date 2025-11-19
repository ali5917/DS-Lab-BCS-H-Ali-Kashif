#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrivalTime;
    Patient* next;

    Patient(string n, int s, int t) : name(n), severity(s), arrivalTime(t), next(nullptr) {}
};

class PriorityQueue {
private:
    Patient* front;

    bool hasHigherPriority(Patient* a, Patient* b) {
        if (a->severity > b->severity) return true;
        if (a->severity == b->severity && a->arrivalTime < b->arrivalTime) return true;
        return false;
    }

public:
    PriorityQueue() : front(nullptr) {}

    void add(string name, int severity, int arrivalTime) {
        Patient* newPatient = new Patient(name, severity, arrivalTime);

        if (!front || hasHigherPriority(newPatient, front)) {
            newPatient->next = front;
            front = newPatient;
            return;
        }

        Patient* current = front;
        while (current->next && !hasHigherPriority(newPatient, current->next)) {
            current = current->next;
        }

        newPatient->next = current->next;
        current->next = newPatient;
    }

    void getNextPatient() {
        if (!front) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "Treating patient: " << front->name << endl;
        Patient* temp = front;
        front = front->next;
        delete temp;
    }

    void updateSeverity(string name, int newSeverity) {
        Patient* current = front;
        Patient* prev = nullptr;

        while (current && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            cout << "Patient not found.\n";
            return;
        }

        int oldArrival = current->arrivalTime;

        if (prev) prev->next = current->next;
        else front = current->next;

        delete current;
        add(name, newSeverity, oldArrival);
    }

    void display() {
        if (!front) {
            cout << "No patients waiting.\n";
            return;
        }
        Patient* current = front;
        cout << "\nPatients in queue (highest priority first):\n";
        while (current) {
            cout << current->name << " | Severity: " << current->severity 
                 << " | Arrival Time: " << current->arrivalTime << endl;
            current = current->next;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.add("Ali", 7, 1);
    pq.add("Ismail", 5, 2);
    pq.add("Hammad", 7, 0);
    pq.add("Sultan", 9, 3);
    pq.display();
    pq.getNextPatient();
    pq.display();
    pq.updateSeverity("Hammad", 10);
    pq.display();
}