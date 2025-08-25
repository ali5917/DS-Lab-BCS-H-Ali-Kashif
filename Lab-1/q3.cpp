#include <iostream>
#include <cstring>
using namespace std;

class Box {
    private:
        int* value;

    public:
        Box (int val = 0) {
            value = new int (val);
        }

        Box (const Box &obj) {
            value = new int (*obj.value);   
        }

        Box& operator=(const Box& other) {
            if (this != &other) {   
                delete value;
                value = new int (*other.value);
            }
            return *this;
        }

        ~Box() {
            delete value;
        }

        void setValue(int val) {
            *value = val;
        }

        int getValue() const {
            return *value;
        }
};

int main() {
    Box box1 (20);
    Box box2 = box1;

    cout << "\nInitial Values\n" << endl;
    cout << "Box 1: " << box1.getValue() << endl;
    cout << "\nBox 2: " << box2.getValue() << endl;
    
    box2.setValue(40);
    cout << "\nAfter Modification of Box 2\n" << endl;
    cout << "Box 1: " << box1.getValue() << endl;
    cout << "\nBox 2: " << box2.getValue() << endl;
    
    // They dont have the same values due to different addresses as DEEP COPY was performed instead of SHALLOW COPY

    return 0;
}