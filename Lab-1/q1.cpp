#include <iostream>
using namespace std;

class BankAccount {
    private:
        float balance;

    public:
        // Default Constuctor
        BankAccount () : balance(0) {
            cout << "\nObject created using Default Constructor\n";
        }
        
        // Parameterized Constuctor
        BankAccount (int bal) : balance(bal) {
            cout << "\nObject created using Parameterized Constructor\n";
        }
        
        // Copy Constuctor
        BankAccount (const BankAccount &obj) {
            cout << "\nObject created using Copy Constructor\n";
            this->balance = obj.balance; 
        }

        float returnBalance () {
            return balance;
        }

        void deductBalance (float amount) {
            balance = max(0.0f, balance - amount);
        }
};

int main () {
    BankAccount account1; 
    cout << "Account 1 Balance: $" << account1.returnBalance() << endl;

    BankAccount account2(1000); 
    cout << "Account 2 Balance: $" << account2.returnBalance() << endl;

    BankAccount account3(account2); 
    account3.deductBalance(200); 
    cout << "Account 3 Balance after deduction: $" << account3.returnBalance() << endl;
    cout << "Account 2 Balance: $" << account2.returnBalance() << endl;

    return 0;
}