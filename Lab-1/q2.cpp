#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    private:
        char* studentName;
        char* examDate;
        int score;
    
    public:
        Exam (const char *n, const char *d, int s) {
            studentName = new char [strlen(n) + 1];
            strcpy(studentName, n);
            
            examDate = new char [strlen(d) + 1];
            strcpy(examDate, d);

            score = s;
        }

        ~Exam() {
            delete[] studentName;
            delete[] examDate;
        }
        
        void setStudentName(const char* n) {
            delete[] studentName;
            studentName = new char[strlen(n) + 1];
            strcpy(studentName, n);
        }

        void setExamDate(const char* d) {
            delete[] examDate;
            examDate = new char[strlen(d) + 1];
            strcpy(examDate, d);
        }

        void setScore(int s) {
            score = s;
        }

        void displayDetails () const {
            cout << "\nStudent Details:\n";
            cout << "Name: " << studentName << endl;
            cout << "Exam Date: " << examDate << endl;
            cout << "Score: " << score << endl;
        }
        
};

int main() {
    Exam exam1("Ali Kashif", "2005-04-21", 86);
    exam1.displayDetails();

    Exam exam2 = exam1; // Shallow Copy
    exam2.displayDetails();
    
    exam2.setStudentName("Bob");
    exam2.setExamDate("2025-09-01");
    exam2.setScore(90);

    exam2.displayDetails();
    exam1.displayDetails();
    
    // Observed issues: 
    // Dangling Pointer because exam1.studentName and exam2.studentName points to the same memory block.
    // Double Deletion because at the end of main, both exam1 and exam2 destructors run. First destructor deletes normally, but when the second runs it tries to delete[] the same memory again.

    return 0;
}