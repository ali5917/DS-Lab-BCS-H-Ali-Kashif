#include <iostream>
using namespace std;

class SafePointer {
    private:
        int* ptr;
        
    public:
        SafePointer() {
            ptr = new int(0);
        }   

        void setValue(int v) {
            if (ptr) *ptr = v;
        }

        int getValue() const {
            if (ptr) return *ptr;
            else {
                cout << "Pointer is null!!!" << endl;
                return 0;
            }
        }

        void release() {
            if (ptr) {
                delete ptr;
                ptr = nullptr;
            }
        }

        ~SafePointer() {
            release();
        }
};

int main() {
    const int num = 5;
    SafePointer students[num];

    cout << "Marks of students:\n";
    for (int i = 0; i < num; i++) {
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        students[i].setValue(mark);
    }

    cout << "\nMarks of students:\n";
    for (int i = 0; i < num; i++) {
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl;
    }
}
